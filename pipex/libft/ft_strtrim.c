/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:36:22 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_start(char *s1, char *set, int i)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s1[i])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int	str_end(char *s1, char *set, int count)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s1[count])
		{
			j = 0;
			count--;
		}
		else
			j++;
	}
	return (count);
}

static void	str_fill(char *str, char *s1, int i, int count)
{
	int	k;

	k = 0;
	while (i <= count)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*str_s1;
	char	*str_set;
	int		i;
	int		count;

	i = 0;
	str_s1 = (char *)s1;
	str_set = (char *)set;
	if (!s1 || !set)
		return (NULL);
	i = str_start(str_s1, str_set, i);
	count = ft_strlen(s1);
	count--;
	count = str_end(str_s1, str_set, count);
	if (count < 0)
		str = malloc ((1) * sizeof(char));
	else
	str = malloc ((count - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str_fill(str, str_s1, i, count);
	return (str);
}

/* int	main(void)
{
	str = malloc ((count - i + 2) * sizeof(char));
	uno por el null y otro por la posición del count retrasada

	char s1[] = "  \t \t \n   \n\n\n\t";
	char set[] = " \n\t";
	char *temp = ft_strtrim(s1, set);
	printf("%s \n", temp);
	free(temp);
	return (0);
} */
