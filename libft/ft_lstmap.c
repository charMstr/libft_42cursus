/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:46:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 21:04:59 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: del function is optional. should be NULL if not used.
**
** note2: iteration of f on each link. see ft_lstiter if no copy wanted.
**
** RETURN: copy of lst which is modified according to (*f) function.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;

	new_list = NULL;
	while (lst)
	{
		if (*f)
			ft_lstadd_back(&new_list, ft_lstnew((*f)(lst->content)));
		if (*del)
			(*del)(lst->content);
		lst = lst->next;
	}
	return (new_list);
}
