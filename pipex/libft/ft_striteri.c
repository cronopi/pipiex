/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:44 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/23 16:25:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	patata(unsigned int nbr, char *pot);
void	potato(unsigned int nbr, char *pot); */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* int	main(void)
{
	char s[] = "estoesalgo";

	ft_striteri(s, &potato);
	return (0);
}

void	patata(unsigned int nbr, char *pot)
{
	(void) nbr;
	write(1, pot, 1);
}

void	potato(unsigned int nbr, char *pot)
{
	printf("%i", nbr);
	write(1, pot, 1);
	write(1, "\n", 1);
} */
