/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:20:30 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == src)
		return (dest);
	i = 0;
	if (src < dest)
	{
		while (i < n--)
			dest2[n] = src2[n];
	}
	else
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	// char *over ="  oldlring         ";
	char str1[] = "oldstring         ";
	//char str2[] = "newpatata         ";

	//(void)str2;
	char *over = str1 + 5;

	//printf("%s\n", (char *)ft_memmove(str1, str2, 8));
	printf("%s\n", (char *)ft_memmove(str1, over, 8));
	return (0);
} */

/*
	oldstold
		 oldstold

	1234
	 1344
	oldstold
		 oldstrin



	newpatata
	0123456789
	char *over = str1 + 5; ring
	(void)over;
	(void)str2;
	printf("old: %s\n", over);
	printf("str1: %s\n", str1);

	printf("%s\n", (char *)ft_memmove(str1, over, 8));

 str1 = oldstring

 str2 = ring */
