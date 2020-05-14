/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_apply_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this functionn will apply a callback func to every item of a tree
**			node that is superior or equal to item_ref_min, and inferior or
**			equal to item_ref_max, according to cmp func.
**			browsing is preorder first. (first root, then left, then right)
**
** note:	Since we operate only on some part of the tree the nodes need to be
**			extracted, applied the applyf, then reinjectected. In order to
**			always respect the cmp func order.
**
** note:	Cumstom function cmp has a similar behavior to ft_strcmp().
**			It is the exact same cmp function used with bstree_del,
**			bstree_getnode(), bstree_add() and bstree_find().
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
**
** note:	In our case setting item_ref_max to NULL will include the nodes
**			from item_ref_min up to NULL items as well.
**			setting item_ref_min to NULL will include only nodes containing
**			NULL->items.
**
** RETURN:	1 if ok
**			0 if failure in callback function. or NULL function pointer.
*/

int			bstree_apply_range(t_bstree **root, t_bstree_range *range, \
		int (*cmp)(void *, void *), int (*applyf)(void *))
{
	t_bstree *substree;
	t_bstree *extracted;
	int res;

	if (!range || !cmp || !applyf)
		return (0);
	substree = NULL;
	while ((extracted = bstree_getnode_range(root, range, cmp)))
		bstree_add(&substree, extracted, cmp);
	if (!substree)
		return (1);
	res = bstree_apply_preorder(substree, applyf);
	while (substree \
			&& (extracted = bstree_getnode(&substree, substree->item, cmp)))
	{
		bstree_add(root, extracted, cmp);
	}
	return (res);
}
