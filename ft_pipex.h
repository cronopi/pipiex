/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:03:18 by roberto           #+#    #+#             */
/*   Updated: 2023/06/06 15:22:19 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_free_paths(char **paths);
int		ft_check_for_quotes(char *cmd1);
char	**ft_split_in_two(char *cmd1);
char	*ft_check_command(char **envp, char *cmd1);

#endif
