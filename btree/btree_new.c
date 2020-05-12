/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will creat a new node. and place item in it.
**
** return:	NULL if malloc failed
**			new node ptr
*/

t_btree			*btree_new(void	*item)
{
	t_btree	*new;

	if (!(new = (t_btree*)malloc(sizeof(t_btree))))
		return NULL;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->item = item;
	return (new);
}
