/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/06/06 15:29:34 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pipex(char *cmd1, char *cmd2, char **envp, char *infile, char *outfile)
{
	int		fd[2];
	pid_t	pid;
	int		file_desc;
	char	*paths_cmd1;
	char	*paths_cmd2;
	char	**args;

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
			perror("pipex: input");
			exit (3);
		}
		dup2(file_desc, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(file_desc);
		paths_cmd1 = ft_check_command(envp, cmd1);
		args = ft_split_in_two(cmd1);
		if (execve(paths_cmd1, args, envp) == -1)
		{
			perror(strerror(errno));
			ft_free_paths(args);
			free(paths_cmd1);
	close (fd[1]);
			exit (5);
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
		args = ft_split_in_two(cmd2);
		if (execve(paths_cmd2, args, envp) == -1)
		{
			perror(strerror(errno));
			ft_free_paths(args);
			free(paths_cmd2);
	close (fd[0]);
			exit (5);
		}
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
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
