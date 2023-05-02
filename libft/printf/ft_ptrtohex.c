/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:43:31 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:43:31 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(int temp, char *str, int i)
{
	if (temp >= 10 && temp <= 16)
		str[i] = temp + 87;
	else
		str[i] = temp + '0';
}

char	*ft_ptrtohex(unsigned long int number)
{
	char					*str;
	int						i;
	int						temp;
	unsigned long int		nbr;

	i = 0;
	str = 0;
	nbr = number;
	while (number > 0)
	{
		number = number / 16;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (i-- > 0)
	{
		temp = nbr % 16;
		convert(temp, str, i);
		nbr = nbr / 16;
	}
	return (str);
}
