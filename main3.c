/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:14:13 by roberto           #+#    #+#             */
/*   Updated: 2023/06/05 14:32:50 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

int ft_check_for_quotes(char *cmd1)
{
	int	i;

	i = 0;
	while (cmd1[i])
	{
		if (cmd1[i] == '\'' || cmd1[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

char **ft_split_in_two(char *cmd1)
{
	char **args;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	if (ft_check_for_quotes(cmd1) == 0)
	{
		args = ft_split(cmd1, ' ');
		return (args);
	}
	j = ft_strlen(cmd1);
	while (i < j)
	{
		if (cmd1[i] == '\'')
		{
			i++;
			while (cmd1[i] != '\'')
				i++;
		}
		if (cmd1[i] == '\"')
		{
			i++;
			while (cmd1[i] != '\"')
				i++;
		}
		if (cmd1[i] == ' ')
			cmd1[i] = '\0';
		k++;
		i++;
	}
	args = malloc(sizeof(char *) * (k + 1));
	i = 0;
	k = 0;
	while (i < j + 1)
	{
		if (cmd1[i] == '\0')
		{
			if (l == 0)
				args[k] = ft_strdup(cmd1); // awk '{count++} END {print count}'
			else
				args[k] = ft_strdup(cmd1 + l);
			k++;
			l = i + 1;
		}
		i++;
	}
	args[k] = NULL;
	i = 0;
	while (i < j)
	{
		if (cmd1[i] == '\0')
			cmd1[i] = ' ';
		i++;
	}
	k = 0;
	while (args[k])
	{
		args[k] = ft_strtrim(args[k], "\'\"");
		k++;
	}
	return (args);
}

char *ft_check_command(char **envp, char *cmd1)
{
	int		j;
	char	*path;
	char	**paths;
	char	**args;
	char	*cmd;
	char	*test;

	j = 0;
	path = NULL;
	test = NULL;
	cmd = NULL;
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
		path = ft_strdup("/bin:/usr/bin");
	paths = ft_split(path, ':');
 	free(path);
	args = ft_split_in_two(cmd1);
	j = 0;
	while (paths[j])
	{
		cmd = ft_strjoin("/", args[0]);
		test = ft_strjoin(paths[j], cmd);
		free(cmd);
		cmd = NULL;
		if (access(test, F_OK) == 0)
			break;
		j++;
		free(test);
		test = NULL;
	}
	if (paths[j] == NULL)
	{
		free(test);
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_paths(args);
		ft_free_paths(paths);
		exit(127);
	}
	cmd = ft_strdup(test);
	ft_free_paths(paths);
	free(test);
	ft_free_paths(args);
	return (cmd);
}

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
