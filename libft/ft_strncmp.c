/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:33:19 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *s1, const char *s2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (num == 0)
		return (0);
	while (i < num - 1 && p1[i] != '\0' && p2[i] != '\0' && p1[i] == p2[i])
		i++;
	return (p1[i] - p2[i]);
}

/* int	main(void)
{
	char str1[] = "zyxbcdefgh";
	char str2[] = "abcdwxyz";

	printf("%i", ft_strncmp(str1, str2, 0));
	return (0);
} */
