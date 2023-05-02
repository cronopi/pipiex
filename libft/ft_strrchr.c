/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:36:10 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i--;
	}
	return (0);
} */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while ((char) str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

/* int	main(void)
{
	char *str = "www.pagaelaluminio.com";
	int c;

	c = '.';
	printf("%s", ft_strrchr(str, c));
	return (0);
} */
