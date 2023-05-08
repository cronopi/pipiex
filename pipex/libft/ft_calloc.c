/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:45:14 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:26:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc (nmemb * size);
	if (str == 0)
		return (NULL);
	while (i < size * nmemb)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

/* int	main(void)
{
	size_t nmemb;
	size_t size;

	nmemb = 2;
	size = 4;
	ft_calloc(nmemb, size);
	//free ();
	//system ()
	return (0);
} */
