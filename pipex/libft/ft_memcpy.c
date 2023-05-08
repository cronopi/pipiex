/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:18:24 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	i = 0;
	p_dest = (char *)dest;
	p_src = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (p_dest);
}

/* int	main(void)
{
	char src[] = "holacaracola";
	char dest[15];

	//ft_memcpy(dest, src, 50);
	printf("%s", (char *)ft_memcpy(dest, src, 60));
	return (0);

	por qué no funciona con = 0
		if (!dest && !src)
		return (0);

	por qué funciona sin esto
		p_dest[i] = '\0';
}
 */
