/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_getnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static t_btree	*btree_getnode_no_child(t_btree **root);
static t_btree	*btree_getnode_one_child(t_btree **root);
static t_btree	*btree_getnode_two_child(t_btree **root);

/*
** note:	This function will extract the first node from the btree, whose
**			item matches the item_ref. Browsing in a dfs infix manner.
**			the scenarios for extracting a node are the same as for deleting
**			nodes. no child, one child or two children.
**
** note:	Cumstom function cmp has a similar behavior to ft_strcmp().
**			It is the exact same cmp function used with btree_del,
**			btree_getnode(), btree_add() and btree_find(). and their red_black
**			versions. It has to handle te case of NULL input, returning 0 if
**			both inputs are NULL. or > 0  if the new_item , and < 0 if the
**			current tree_item is NULL so that we keep null at the far right.
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
** RETURN:	the extracted first node containing the matching item.
**			NULL if no match.
*/

t_btree	 *btree_getnode(t_btree **root, void *item_ref, \
		int (*cmp)(void *, void *))
{
	t_btree *returned_node;

	if (!root || !*root || !cmp)
		return (NULL);
	if (!cmp(item_ref, (*root)->item))
	{
		if (!(*root)->left && !(*root)->right)
			returned_node = btree_getnode_no_child(root);
		else if ((*root)->left && (*root)->right)
			returned_node = btree_getnode_two_child(root);
		else
			returned_node = btree_getnode_one_child(root);
		returned_node->parent = NULL;
		returned_node->left = NULL;
		returned_node->right = NULL;
		return (returned_node);
	}
	if (!(returned_node = btree_getnode(&(*root)->left, item_ref, cmp)))
		returned_node = btree_getnode(&(*root)->right, item_ref, cmp);
	return (returned_node);
}

/*
** note:	this function is called when the node to be deleted has no childs.
*/

static t_btree	*btree_getnode_no_child(t_btree **root)
{
	t_btree *get_me;

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

static t_btree	*btree_getnode_one_child(t_btree **root)
{
	t_btree *child;
	t_btree *get_me;

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

static t_btree	*btree_getnode_two_child(t_btree **root)
{
	void	*get_me_item;
	t_btree *get_me_node;

	get_me_node = *root;
	get_me_item = get_me_node->item;
	root = &(*root)->right;
	while ((*root)->left)
		root = &(*root)->left;
	get_me_node->item = (*root)->item;
	(*root)->item = get_me_item;
	if (!(*root)->left && !(*root)->right)
		return (btree_getnode_no_child(root));
	else
		return (btree_getnode_one_child(root));
}
