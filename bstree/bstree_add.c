/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function will insert a new node in the bstree, the insertion
**			position is decided with the cmp function. for each node, if cmp
**			returns a negative value go left, if >= 0 go right.
**
** note:	node is a new node previously malloced.
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

void	bstree_add(t_bstree **root, t_bstree *node, int (*cmp)(void *, void *))
{
	if (!root || !cmp || !node)
		return;
	if (!*root)
	{
		*root = node;
		return;
	}
	node->parent = *root;
	if (cmp(node->item, (*root)->item) < 0)
		bstree_add(&(*root)->left, node , cmp);
	else
		bstree_add(&(*root)->right, node , cmp);
}
