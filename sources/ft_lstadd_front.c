/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 18:41:55 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: take as first parameter the address of an existing link, or a pointer
** to a linked list (therefore a t_list ** pointer)
**
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *new;
	void	*tmp;

	if (!alst)
		return (NULL);

}
