/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:14 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:25:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
}

/* int	main(void)
{
	const char s[] = "Esto es un string";
	char *str;

	str =  ft_strdup(s);
	printf("%s", str);
	free (str);
	return (0);
} */
