/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:28:21 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/24 15:11:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_lengh;
	size_t	src_lengh;

	src_lengh = ft_strlen(src);
	if (!dst && !size)
		return (src_lengh);
	i = 0;
	dest_lengh = ft_strlen(dst);
	if (size <= dest_lengh)
		return (src_lengh + size);
	else
	{
		while (i + dest_lengh < size - 1 && src[i] != '\0')
		{
			dst[dest_lengh + i] = src[i];
			i++;
		}
		dst[dest_lengh + i] = '\0';
	}
	return (dest_lengh + src_lengh);
}

/* size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && !size)
		return (slen);
	i = 0;
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (slen + size);
	else
	{
		while (i + dlen < size - 1 && i < dlen + slen && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + slen);
} */

/* int	main(void)
{
	char src[] = "lorem ipsum dolor sit amet";
	char dst[10] = "a";
	printf("%li\n", ft_strlcat(dst, src, 0));
	//printf("%li\n", strlcat(dst, src, 50));
	return (0);
} */
