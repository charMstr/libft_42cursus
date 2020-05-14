/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_make_nodes_uniq.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function makes sure that in the entire tree there no two node
**			containing the same item, according to cmp function. If there is
**			more than one. del will remove node->item. and node will be freed.
**
**	note:	refer to bstree_rb_make_nodes_uniq() if you want to do the same
**			operation in a red / black tree.
**
**	note:	refer to bstree_make_item_uniq() if you want to do the same on
**			a single item_ref.
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

void	bstree_make_nodes_uniq(t_bstree **root, int (*cmp)(void *, void *),\
		void (*del)(void *))
{
	t_bstree *new_root;
	t_bstree *new_node;

	new_root = NULL;
	if (!root || !*root || !cmp || !del)
		return ;
	while (*root)
	{
		new_node = bstree_getnode(root, (*root)->item, cmp);
		bstree_del(root, new_node->item, cmp, del);
		bstree_add(&new_root, new_node, cmp);
	}
	*root = new_root;
}
