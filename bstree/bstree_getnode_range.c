/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_getnode_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

static t_bstree	*bstree_getnode_range_assist(t_bstree **root, \
		t_bstree_range *range, int (*cmp)(void *, void *));
static t_bstree	*bstree_getnode_no_child(t_bstree **root);
static t_bstree	*bstree_getnode_one_child(t_bstree **root);
static t_bstree	*bstree_getnode_two_child(t_bstree **root);

/*
** note:	This function is similar to the bstree_getnode() function. But It
**			will extract from the tree the first node that is greater or equal
**			to item_ref_min and lower or equal to item_ref_max, according to
**			the cmp function.
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
** RETURN:	node, the tree is cut off.
**			NULL if nothing was removed from the old red black bstree..
*/

t_bstree			*bstree_getnode_range(t_bstree **root, \
		t_bstree_range *range, int (*cmp)(void *, void *))
{
	if (!root || !*root || !cmp || !range)
		return (NULL);
	return (bstree_getnode_range_assist(root, range, cmp));
}

/*
** note:	this assisting function will recurse and move from a current node
**			to another, not modifying root unless necessary. and avoiding
**			unecessary repeated conditions.
*/

static t_bstree	*bstree_getnode_range_assist(t_bstree **root, \
		t_bstree_range *range, int (*cmp)(void *, void *))
{
	t_bstree *returned_node;

	if (!*root)
		return (NULL);
	if (cmp(range->item_ref_min , (*root)->item) <= 0 \
			&& cmp(range->item_ref_max , (*root)->item) >= 0)
	{
		if (!(*root)->left && !(*root)->right)
			returned_node = bstree_getnode_no_child(root);
		else if ((*root)->left && (*root)->right)
			returned_node = bstree_getnode_two_child(root);
		else
			returned_node = bstree_getnode_one_child(root);
		returned_node->parent = NULL;
		returned_node->left = NULL;
		returned_node->right = NULL;
		return (returned_node);
	}
	if (!(returned_node = bstree_getnode_range_assist(&(*root)->left, range, \
					cmp)))
		returned_node = bstree_getnode_range_assist(&(*root)->right, range, \
				cmp);
	return (returned_node);
}

/*
** note:	this function is called when the node to be deleted has no childs.
*/

static t_bstree	*bstree_getnode_no_child(t_bstree **root)
{
	t_bstree *get_me;

	get_me = *root;
	if (get_me->parent && get_me->parent->right == get_me)
		get_me->parent->right = NULL;
	else if (get_me->parent && get_me->parent->left == get_me)
		get_me->parent->left = NULL;
	*root = NULL;
	return (get_me);
}

/*
** note:	this funciton is called when the node to be deleted has only one
**			child. the child goes up.
*/

static t_bstree	*bstree_getnode_one_child(t_bstree **root)
{
	t_bstree *child;
	t_bstree *get_me;

	get_me = *root;
	if (get_me->right)
		child = get_me->right;
	else
		child = get_me->left;
	if (get_me->parent && get_me->parent->right == get_me)
		get_me->parent->right = child;
	else if (get_me->parent && get_me->parent->left == get_me)
		get_me->parent->left = child;
	child->parent = get_me->parent;
	*root = child;
	return (get_me);
}

/*
** note:	this function is called when we need to delete a node that has two
**			children. That node is not deleted effectively, its item is deleted
**			and is replaced with another item. The new item is found in the
**		 	left-most node from the right branch. That node is deleted
**			effectively.
*/

static t_bstree	*bstree_getnode_two_child(t_bstree **root)
{
	void	*get_me_item;
	t_bstree *get_me_node;

	get_me_node = *root;
	get_me_item = get_me_node->item;
	root = &(*root)->right;
	while ((*root)->left)
		root = &(*root)->left;
	get_me_node->item = (*root)->item;
	(*root)->item = get_me_item;
	if (!(*root)->left && !(*root)->right)
		return (bstree_getnode_no_child(root));
	else
		return (bstree_getnode_one_child(root));
}
