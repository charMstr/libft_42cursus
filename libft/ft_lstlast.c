/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:23 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 15:02:40 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RETURN: pointer to very last link, NULL if the head of list pointer was NULL
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *previous;

	previous = NULL;
	while (lst != NULL)
	{
		previous = lst;
		lst = lst->next;
	}
	return (previous);
}
