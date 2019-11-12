/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 19:46:10 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: iteration of f function on every CONTENTS of every links of the list
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!(*f))
		return ;
	while (lst)
	{
		if (!(lst->content == NULL))
			(*f)(lst->content);
		lst = lst->next;
	}
}
