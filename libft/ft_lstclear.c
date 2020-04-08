/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:47:24 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 18:59:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	deletes element and all following ones: different from ft_lstdelone
**
** note:	if you want to delete from the middle of the list:
**			-	it puts the pointer to NULL so it ends the list here.
**			-	1st arg: &(previous->next) should be used to NULLify the
**				correct pointer.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*then;

	current = *lst;
	while (current)
	{
		then = current->next;
		ft_lstdelone(current, del);
		current = then;
	}
	*lst = NULL;
}
