/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:24:48 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:25:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;
	char	cast_c;

	ptr = (char *)str;
	i = 0;
	cast_c = (char) c;
	while (ptr[i] != '\0')
	{
		if (cast_c == ptr[i])
			return (&ptr[i]);
		i++;
	}
	if (cast_c == '\0')
		return (&ptr[i]);
	return (0);
}

/* char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while ((char)str[i] != '\0')
	{
		if ((char)c == (char)str[i])
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
} */

/* int	main(void)
{
	const char str[] = "teste";
	int c;

	c = 'a';
	printf("%s \n", ft_strchr(str, c));
	return (0);
} */
