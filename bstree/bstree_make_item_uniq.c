/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_make_item_uniq.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function makes sure there is no more that one node
**			containing an item macthing item_ref in the tree, according
**			to cmp function. If there is more than one. del will remove
**			node->item. and node will be freed.
**
**	note:	refer to bstree_rb_uniq() if you want to do the same operation
**			in a red black tree.
**
** note:	Cumstom function cmp has a similar behavior to ft_strcmp().
**			It is the exact same cmp function used with bstree_del, bstree_get,
**			bstree_add() and bstree_find(). and their red_black versions.
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

void	bstree_make_item_uniq(t_bstree **root, void *item_ref, \
		int (*cmp)(void *, void *), void (*del)(void*))
{
	t_bstree *uniq;

	if (!cmp || !del || !root || !*root)
		return ;
	uniq = bstree_getnode(root, item_ref, cmp);
	if (!uniq)
		return ;
	bstree_del(root, item_ref, cmp, del);
	bstree_add(root, uniq, cmp);
}
