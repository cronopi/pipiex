/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/05/16 11:35:49 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"



void	ft_pipex(char *cmd1, char *cmd2, char **envp, char *infile, char *outfile)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		file_desc;
	char	**paths;
	char	**paths2;
	char	*path;
	char	*cmd;
	char	**args;
	char	**args2;
	int		j;
	int		i;

	j = 0;
	while(envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[j] + 5);
			break;
		}
		j++;
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
		//printf("esto que imprime %s\n", paths[j]);
		j++;
		free(cmd);
	}

	paths2 = ft_split(path, ':');
	args2 = ft_split(cmd2, ' ');
	i = 0;
	while (paths2[i] != NULL)
	{
		cmd2 = ft_strjoin("/", args2[0]);
		paths2[i] = ft_strjoin(paths2[i], cmd2);
		if (access(paths2[i], F_OK) == 0)
			break;
		//printf("y lo otro que imprime %s\n", paths[j]);
		i++;
		free(cmd2);
	}
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
		if (execve(paths[j], args, envp) == -1)
		{
			perror("Error al ejecutar execve\n");
			exit (4);
		}
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Error al crear el proceso padre-hijo\n");
		exit (5);
	}
	else if (pid2 == 0)
	{
		file_desc = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file_desc < 0)
		{
			perror("Error al abrir el archivo\n");
			exit (6);
		}
		dup2(fd[0], STDIN_FILENO);
		dup2(file_desc, STDOUT_FILENO);
		close(fd[1]);
		if (execve(paths2[i], args2, envp) == -1)
		{
			perror("Error al ejecutar execve\n");
			exit (4);
		}
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(path);
	exit (0);
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
	return (0);
}
