/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:39:30 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:39:31 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(int i, unsigned int nbr, char **str)
{
	int	temp;

	while (i-- > 0)
	{
		temp = nbr % 16;
		if (temp >= 10 && temp <= 16)
			(*str)[i] = temp + 87;
		else
			(*str)[i] = temp + '0';
		nbr = nbr / 16;
	}
}

char	*ft_itohex(int number)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	i = 0;
	if (number == 0)
		i = 1;
	str = 0;
	nbr = (unsigned int)(4294967296 + number);
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	nbr = (unsigned int)(4294967296 + number);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	ft_convert(i, nbr, &str);
	return (str);
}
