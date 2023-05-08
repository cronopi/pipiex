/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:17:08 by rcastano          #+#    #+#             */
/*   Updated: 2023/01/16 11:17:08 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list *l = lstnew(strdup("nyacat"));
	t_list *n = lstnew(strdup("OK"));

	ft_lstadd_front(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		printf("correct");
	}
	printf("false");

	//new->next;
} */
