/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:40:38 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:40:39 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_string(unsigned long int nbr, char *str, int i)
{
	int	temp;

	temp = 0;
	while (i-- > 0)
	{
		temp = nbr % 10;
		str[i] = temp + '0';
		nbr = nbr / 10;
	}
}

static int	string_size(unsigned long int n, int i)
{
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_utoa(unsigned int n)
{
	char				*str;
	int					i;
	unsigned long int	nbr;

	i = 0;
	nbr = (unsigned long int)n;
	i = string_size(nbr, i);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	fill_string(nbr, str, i);
	return (str);
}

char	*ft_print_utoa(unsigned int number)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_utoa(number);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}
