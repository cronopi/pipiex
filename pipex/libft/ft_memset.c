/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:19 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	char	*string;

	string = (char *)ptr;
	i = 0;
	while (i < num)
	{
		string[i] = (char)value;
		i++;
	}
	return (string);
}

/* int	main(void)
{
	char ptr[] = "holacaracola";
	ft_memset(ptr, 'x', 3);
	printf("%s\n", ptr);
	return (0);
}*/
