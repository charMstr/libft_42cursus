/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_rb_subtree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

typedef struct		s_cmp_min_max
{
	int				(*cmp)(void *, void *);
	void			*item_min;
	void			*item_max;
}					t_cmp_min_max;

static t_rb_node	*btree_rb_subtree_assist(t_rb_node **root, \
		t_rb_node *current, t_cmp_min_max *min_max);
static void			btree_rb_get_either_is_red(t_rb_node **root, \
		t_rb_node *current);
static				t_rb_node *btree_rb_get_node_two_child(t_rb_node **root, \
		t_rb_node *current);

/*
** note:	This function is similar to the btree_rb_get() function.But It will
**			extract from the red/black tree ALL the nodes that are greater or
**			equal to item_ref_min and lower or equal to item_ref_max,
**			according to the cmp function, and place them in a new subtree.
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
**
** note:	In our case setting item_ref_max to NULL will include the nodes
**			from item_ref_min up to NULL items as well.
**			setting item_ref_min to NULL will include only nodes containing
**			NULL->items.
**
** RETURN:	new subtree. the old tree is cut off.
**			NULL if nothing was removed from the old red black btree..
*/

t_rb_node			*btree_rb_subtree(t_rb_node **root, void *item_ref_min, \
		void *item_ref_max, int (*cmp)(void *, void *))
{
	t_rb_node 		*extracted;
	t_rb_node 		*subtree;
	t_cmp_min_max	cmp_min_max;

	subtree = NULL;
	if (!root || !*root || !cmp)
		return (NULL);
	cmp_min_max.cmp = cmp;
	cmp_min_max.item_min = item_ref_min;
	cmp_min_max.item_max = item_ref_max;
	while ((extracted = btree_rb_subtree_assist(root, *root, &cmp_min_max)))
	{
		extracted->parent = NULL;
		extracted->left = NULL;
		extracted->right = NULL;
		extracted->color = RB_RED;
		btree_rb_add(&subtree, extracted, cmp);
	}
	return (subtree);
}

/*
** note:	this assisting function will recurse and move from a node to
**			another, while not modifying root unless necessary.
*/

static t_rb_node	*btree_rb_subtree_assist(t_rb_node **root, \
		t_rb_node *current, t_cmp_min_max *cmp_min_max)
{
	t_rb_node	*res;

	if (!*root || !current)
		return (NULL);
	if (cmp_min_max->cmp(cmp_min_max->item_min , current->item) <= 0 \
			&& cmp_min_max->cmp(cmp_min_max->item_max , current->item) >= 0)
	{
		res = current;
		if (current->left && current->right)
			res = btree_rb_get_node_two_child(root, current);
		else if (current->color == RB_RED || current->right || current->left)
			btree_rb_get_either_is_red(root, current);
		else if (!current->parent)
			*root = NULL;
		else
			btree_rb_get_balance(root, current, 1);
		return (res);
	}
	if (!(res = btree_rb_subtree_assist(root, current->left, cmp_min_max)))
		res = btree_rb_subtree_assist(root, current->right, cmp_min_max);
	return (res);
}

/*
** note:	this function is called in the case: either the node to be
**			extracted is red, or its children is red.
*/

static void		btree_rb_get_either_is_red(t_rb_node **root, \
		t_rb_node *current)
{
	t_rb_node *red_child;

	red_child = current->left;
	if (!red_child)
		red_child = current->right;
	if (current == *root)
		*root = red_child;
	if (current->parent && current->parent->right == current)
		current->parent->right = red_child;
	else if (current->parent && current->parent->left == current)
		current->parent->left = red_child;
	if (red_child)
	{
		red_child->parent = current->parent;
		red_child->color = RB_BLACK;
	}
}

/*
** note:	this function is called when we need to get a node that has two
**			children. That node is not extracted effectively, its item is first
**			swapped with another item. The new item is found in the
**		 	left-most node from the right branch. That node is then extracted
**			effectively (now containing the item we wanted to delete).
*/

static t_rb_node	*btree_rb_get_node_two_child(t_rb_node **root, \
		t_rb_node *current)
{
	void		*get_me_item;
	t_rb_node	*get_me_node;

	get_me_node = current;
	get_me_item = current->item;
	get_me_node = get_me_node->right;
	while (get_me_node->left)
		get_me_node = get_me_node->left;
	current->item = get_me_node->item;
	get_me_node->item = get_me_item;
	if (get_me_node->color == RB_RED || get_me_node->right \
			|| get_me_node->left)
		btree_rb_get_either_is_red(root, get_me_node);
	else
		btree_rb_get_balance(root, get_me_node, 1);
	return (get_me_node);
}
