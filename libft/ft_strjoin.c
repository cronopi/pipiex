/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:27:07 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc ((i + j + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	fill_string(str, str_s1, str_s2);
	return (str);
}
/*
int	main(void)
{
	char s1[] = "my favorite animal is";
	char s2[] = "the nyancat";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
} */
