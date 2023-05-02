/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:38:32 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	size_t			j;

	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	d = malloc(sizeof(char) * (len + 1));
	if (d == 0)
		return (NULL);
	while (j < len && s[start] != '\0')
	{
		d[j] = s[start];
		start++;
		j++;
	}
	d[j] = '\0';
	return (d);
}

/* int	main(void)
{
	char const s[] = "hola";
	unsigned int start;
	size_t len;
	char *str;

	start = 2;
	len = 3;
	str = ft_substr(s, start, len);
	printf("%s", str);
	free(str);
	return (0);
} */
