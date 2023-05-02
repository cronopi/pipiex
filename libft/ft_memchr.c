/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:34 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c1;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)str;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (c1 == ptr[i])
			return (&ptr[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char str[] = "www.tutorialspoint.com";
	int c;

	c = '.';
	printf("%s", (char *)ft_memchr(str, c, 2));

	return (0);
} */
