/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:36:46 by rcastano          #+#    #+#             */
/*   Updated: 2023/03/01 10:53:47 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_index3(char *str, int i, va_list arguments, int *j)
{
	int		every_integer;
	char	*tmp_str;

	if (str[i + 1] == 'u')
	{
		every_integer = va_arg(arguments, unsigned int);
		tmp_str = ft_print_utoa(every_integer);
		(*j) = (*j) + ft_strlen(tmp_str);
		free(tmp_str);
	}
	else if (str[i + 1] == 'x')
	{
		every_integer = va_arg(arguments, int);
		ft_hex_print(tmp_str = ft_itohex(every_integer), 1);
		(*j) = (*j) + ft_strlen(tmp_str);
		free(tmp_str);
	}
	else if (str[i + 1] == 'X')
	{
		every_integer = va_arg(arguments, int);
		ft_hex_print(tmp_str = ft_itohex(every_integer), 2);
		(*j) = (*j) + ft_strlen(tmp_str);
		free(tmp_str);
	}
}

void	ft_index2(char *str, int i, va_list arguments, int *j)
{
	int		every_integer;
	char	*every_string;

	if (str[i + 1] == 'c')
	{
		ft_putchar(va_arg(arguments, int));
		(*j)++;
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		every_integer = va_arg(arguments, int);
		ft_putnbr_fd(every_integer, 1);
		every_string = ft_itoa(every_integer);
		(*j) = (*j) + ft_strlen(every_string);
		free(every_string);
	}
	else if (str[i + 1] == 's')
	{
		every_string = va_arg(arguments, char *);
		ft_putstr(every_string);
		if (every_string)
		(*j) = (*j) + ft_strlen(every_string);
		else
			(*j) = (*j) + 6;
	}
}

int	ft_index(char *str, int i, va_list arguments, int *j)
{
	void			*every_pointer;
	char			*tmp_str;

	if (str[i + 1] == 'p')
	{
		every_pointer = va_arg(arguments, void *);
		tmp_str = ft_hex_print_void(every_pointer);
		if (every_pointer != 0)
			(*j) = (*j) + ft_strlen(tmp_str) + 2;
		else
			(*j) = (*j) + ft_strlen(tmp_str);
		free(tmp_str);
	}
	else if (str[i + 1] == '%')
	{
		write(1, "%", 1);
		(*j)++;
	}
	ft_index2(str, i, arguments, j);
	ft_index3(str, i, arguments, j);
	i = i + 2;
	return (i);
}

int	ft_string_copy(char *str, va_list arguments)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = ft_index(str, i, arguments, &j);
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			j++;
		}
	}
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arguments;

	va_start (arguments, str);
	i = ft_string_copy ((char *)str, arguments);
	va_end(arguments);
	return (i);
}
