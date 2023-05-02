/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:37:18 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:37:49 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_print(char *str, int upper_lower)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (upper_lower == 2)
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}
