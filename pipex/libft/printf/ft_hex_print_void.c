/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print_void.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:38:08 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:38:39 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

char	*ft_hex_print_void(void *ptr)
{
	char	*str;

	if (ptr == 0)
		str = ft_strdup("0x0");
	else
	{
		str = ft_ptrtohex((unsigned long int)ptr);
		write(1, "0x", 2);
	}
	ft_hex_print(str, 1);
	return (str);
}
