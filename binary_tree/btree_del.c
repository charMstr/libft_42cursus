/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will delete any node in the tree whose item is
**			matching the item_ref, according to the cmp function.
**
** note:	if item_ref is NULL, then all the nodes w/ a node->item NULL should
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

static void	btree_del_node_no_child(t_btree **root, void(*del)(void*));
static void	btree_del_node_one_child(t_btree **root, void(*del)(void*));
static void	btree_del_node_two_child(t_btree **root, void(*del)(void*));

void	btree_del(t_btree **root, void *item_ref, int (*cmp)(void *, void *), \
		void (*del)(void*))
{
	if (!root || !*root || !cmp || !del)
		return ;
	if (!cmp(item_ref , (*root)->item))
	{
		if (!(*root)->left && !(*root)->right)
			btree_del_node_no_child(root, del);
		else if ((*root)->left && (*root)->right)
			btree_del_node_two_child(root, del);
		else
			btree_del_node_one_child(root, del);
		btree_del(root, item_ref, cmp, del);
		return ;
	}
	btree_del(&(*root)->left, item_ref, cmp, del);
	btree_del(&(*root)->right, item_ref, cmp, del);
}

/*
** note:	this function is called when the node to be deleted has no childs.
*/

static void	btree_del_node_no_child(t_btree **root, void(*del)(void*))
{
	t_btree *del_me;

	del_me = *root;
	del(del_me->item);
	if (del_me->parent && del_me->parent->right == del_me)
		del_me->parent->right = NULL;
	else if (del_me->parent && del_me->parent->left == del_me)
		del_me->parent->left = NULL;
	free(del_me);
	*root = NULL;
}

/*
** note:	this funciton is called when the node to be deleted has only one
**			child. the child goes up.
*/

static void	btree_del_node_one_child(t_btree **root, void(*del)(void*))
{
	t_btree *child;
	t_btree *del_me;

	del_me = *root;
	if (del_me->right)
		child = del_me->right;
	else
		child = del_me->left;
	del(del_me->item);
	if (del_me->parent && del_me->parent->right == del_me)
		del_me->parent->right = child;
	else if (del_me->parent && del_me->parent->left == del_me)
		del_me->parent->left = child;
	child->parent = del_me->parent;
	free(del_me);
	*root = child;
}

/*
** note:	this function is called when we need to delete a node that has two
**			children. That node is not deleted effectively, its item is deleted
**			and is replaced with another item. The new item is found in the
**		 	left-most node from the right branch. That node is deleted
**			effectively.
*/

static void	btree_del_node_two_child(t_btree **root, void(*del)(void*))
{
	void	*del_me_item;
	t_btree *del_me_node;

	del_me_node = *root;
	del_me_item = del_me_node->item;
	root = &(*root)->right;
	while ((*root)->left)
		root = &(*root)->left;
	del_me_node->item = (*root)->item;
	(*root)->item = del_me_item;
	if (!(*root)->left && !(*root)->right)
		btree_del_node_no_child(root, del);
	else
		btree_del_node_one_child(root, del);
}
