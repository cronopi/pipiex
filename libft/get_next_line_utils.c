/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:02:30 by rcastano          #+#    #+#             */
/*   Updated: 2023/02/13 14:02:30 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t	ft_strlen_mod(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
} */

/* char	*ft_strdup_mod(const char *s)
{
	char	*d;
	int		i;
	int		j;

	j = 0;
	while (s[j])
		j++;
	d = malloc(sizeof(const char) * (j + 1));
	if (d == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
} */

static void	fill_string(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
		if (s1[i - 1] == '\n')
			break ;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
		if (s2[j - 1] == '\n')
			break ;
	}
	str[i] = '\0';
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	char	*str_s1;
	char	*str_s2;

	str_s1 = (char *)s1;
	str_s2 = (char *)s2;
	i = 0;
	j = 0;
	if (s1)
		i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc ((i + j + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	fill_string(str, str_s1, str_s2);
	if (str_s1 != 0)
		free(str_s1);
	return (str);
}

/* char	*ft_substr_mod(char const *s, unsigned int start, size_t len)
{
	char			*d;
	size_t			j;

	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	d = malloc(sizeof(char) * (len + 1));
	if (d == 0)
		return (NULL);
	while (j < len && s[start] != '\0')
	{
		d[j] = s[start];
		start++;
		j++;
	}
	d[j] = '\0';
	return (d);
} */
