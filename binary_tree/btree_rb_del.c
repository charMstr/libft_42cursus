/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_rb_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will delete any node in the red/black tree whose item
**			is matching the item_ref, according to the cmp function.
**
** note:	Refer to btree_rb_delone() if you want to delete only the first met
**			node.
**
** note:	If item_ref is NULL, then all the nodes w/ a node->item NULL should
**			be removed.
**
** note:	the del function will free the (void*)(node->item).
**
** note:	Cumstom function cmp has a similar behavior to ft_strcmp().
**			It is the exact same cmp function used with btree_del, btree_get(),
**			btree_add() and btree_find(). and their red_black versions.
**			It has to handle te case of NULL input, returning 0 if both inputs
**			are NULL. or > 0  if the new_item , and < 0 if the current
**			tree_item is NULL so that we keep null at the far right.
**
**			Therefore cmp's start should always look like this:
**			int	cmp_func(void *new_item, void *tree_item)
**			{
**				if (!new_item && !tree_item)
**					return (0);
**				if (!new_item)
**					return (1);
**				if (!tree_item)
**					return (-1);
**				...
*/

void		btree_rb_del(t_rb_node **root, void *item_ref, \
		int (*cmp)(void *, void *), void (*del)(void*))
{
	t_rb_node *del_me;

	while ((del_me = btree_rb_get(root, item_ref, cmp)))
	{
		del(del_me->item);
		free(del_me);
	}
}
