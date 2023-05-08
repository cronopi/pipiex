/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:33:46 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/25 17:14:07 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*stack;
	char	*tmp_needle;

	i = 0;
	stack = (char *)haystack;
	tmp_needle = (char *)needle;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && stack[i] != '\0')
	{
		j = 0;
		while (stack[i] && i + j < len && tmp_needle[j] == stack[i + j])
		{
			if (tmp_needle[j + 1] == '\0')
			{
				return (&stack[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char haystack[] = "";
	char needle[] = "xx";
	printf("%s", ft_strnstr(haystack, needle, 4294967295));
	return (0);
} */
/*
j++

j = 7
str[j++] = 7 + 1 = 8 el checkeo de la posición lo hace antes del incremento
str[8]

++j

j = 7

str[++j] = j + 1  = 8 el checkeo de la posición lo hace despues del incremento
str[8]


si el incremento se encuentra en una línea "vacía" no afecta
el orden de la operación.

while(str[] ! null)
{
	str[] = str2[]
	i++;  or ++i;
}

si el incremento se encuentra en una línea que tiene varias
operaciones SI afecta el orden de la operacion

while(str[i++] ! null)   or   while(str[++i] ! null)
	str[] = str2[]					str[] = str2[]

*/
