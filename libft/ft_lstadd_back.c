/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 15:47:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: arg1: head of list, (ex: &head)	arg2: new link to be added
**
** note2: if *alst is NULL, it means the list was empty. new list is created
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;
	t_list *previous;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	previous = NULL;
	while (tmp != NULL)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	previous->next = new;
}
