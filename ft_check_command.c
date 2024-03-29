/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:31 by roberto           #+#    #+#             */
/*   Updated: 2023/06/12 14:51:45 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_paths_is_null(char **paths, int j, char **args, char *test)
{
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
}

int	ft_path_cmd( char **paths, char **args, char **test)
{
	int		j;
	char	*cmd;

	j = 0;
	cmd = NULL;
	while (paths[j])
	{
		cmd = ft_strjoin("/", args[0]);
		*test = ft_strjoin(paths[j], cmd);
		free(cmd);
		cmd = NULL;
		if (access(*test, F_OK) == 0)
			break ;
		j++;
		free(*test);
		*test = NULL;
	}
	return (j);
}

char	**split_path(char **paths, char **envp)
{
	char	*path;
	int		j;

	j = 0;
	path = NULL;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[j] + 5);
			break ;
		}
		j++;
	}
	if (path == NULL)
		path = ft_strdup("/bin:/usr/bin");
	paths = ft_split(path, ':');
	free(path);
	return (paths);
}

char	*ft_check_command(char **envp, char *cmd1)
{
	int		j;
	char	**paths;
	char	**args;
	char	*cmd;
	char	*test;

	j = 0;
	test = NULL;
	cmd = NULL;
	paths = NULL;
	paths = split_path(paths, envp);
	args = ft_split_in_two(cmd1);
	j = ft_path_cmd(paths, args, &test);
	ft_paths_is_null(paths, j, args, test);
	cmd = ft_strdup(test);
	ft_free_paths(paths);
	free(test);
	ft_free_paths(args);
	return (cmd);
}
