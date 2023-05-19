/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/05/19 18:40:33 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char *ft_check_command(char **envp, char *cmd1)
{
	int j;
	char *path;
	char **paths;
	char **args;
	char *cmd;

	j = 0;
	path = NULL;
	while(envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[j] + 5);
			break;
		}
		j++;
	}
	if (path == NULL)
	{
		perror("No 'PATH' environment variable found\n");
		exit(1);
	}
	paths = ft_split(path, ':');
	args = ft_split(cmd1, ' ');
	j = 0;
	while (paths[j] != NULL)
	{
		cmd = ft_strjoin("/", args[0]);
		paths[j] = ft_strjoin(paths[j], cmd);
		if (access(paths[j], F_OK) == 0)
			break;
		j++;
		free(cmd);
	}
	if (paths[j] == NULL)
	{
		perror("No such file or directory\n");
		exit(1);
	}
	free(path);
	return (paths[j]);
}

void	ft_pipex(char *cmd1, char *cmd2, char **envp, char *infile, char *outfile)
{
	int		fd[2];
	pid_t	pid;
	int		file_desc;
	char	*paths_cmd1;
	char	*paths_cmd2;


	if (pipe(fd) == -1)
	{
		perror("Error al crear la tubería");
		exit (1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Error al crear el proceso padre-hijo\n");
		exit (2);
	}
	else if (pid == 0)
	{
		file_desc = open(infile, O_RDONLY);
		if (file_desc < 0)
		{
			perror("Error al abrir el archivo\n");
			exit (3);
		}
		dup2(file_desc, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(file_desc);
		paths_cmd1 = ft_check_command(envp, cmd1);
		if (execve(paths_cmd1, ft_split(cmd1, ' '), envp) == -1)
		{
			/* perror("Error al ejecutar execve hijo\n");
			exit (4); */
			perror(strerror(errno));
			exit (EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, WNOHANG);
		file_desc = open(outfile, O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (file_desc < 0)
		{
			perror(strerror(errno));
			exit (5);
		}
		dup2(fd[0], STDIN_FILENO);
		dup2(file_desc, STDOUT_FILENO);
		close(fd[1]);
		close(file_desc);
		paths_cmd2 = ft_check_command(envp, cmd2);
		if (execve(paths_cmd2, ft_split(cmd2, ' '), envp) == -1)
		{
			/* perror("Error al ejecutar execve padre\n");
			exit (4); */
			perror(strerror(errno));
			exit (EXIT_FAILURE);
		}
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
	//waitpid(pid2, NULL, 0);
	exit (11);
}

int main (int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		ft_pipex(argv[2], argv[3], envp, argv[1], argv[4]);
	}
	else
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (12);
}
