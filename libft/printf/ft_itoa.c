/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:11:04 by rcastano          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:15 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_string(long int nbr, char *str, int i)
{
	int	temp;

	temp = 0;
	while (i-- > 0)
	{
		if (nbr >= 0)
		{
			temp = nbr % 10;
			str[i] = temp + '0';
			nbr = nbr / 10;
		}
	}
}

static int	string_size(long long int n, int i)
{
	if (n == 0)
		i = 1;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	itoa_sign(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	long long int	nbr;
	int				sign;

	sign = itoa_sign(n);
	i = 0;
	nbr = (long long int)n;
	i = string_size(nbr, i);
	if (nbr < 0)
		nbr = nbr * -1;
	str = malloc(sizeof(char) * (i + sign + 1));
	if (!str)
		return (NULL);
	str[i + sign] = '\0';
	fill_string(nbr, str, i + sign);
	if (sign)
		str[0] = '-';
	return (str);
}
