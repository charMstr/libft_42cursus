/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_left_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	This function operates a left rotation on a given node.
**			The root goes left and down, while the root->right child becomes
**			new_root. If the root->right had a left child, it gets swaped to
**			the other side, and becomes the right child of the new_root->left.
**
**	note:	the rotation is not performed if the root->right child is NULL.
*/
#include "btree.h"

void	btree_left_rotation(t_btree **root)
{
	t_btree *new_root;

	if (!root || !*root || !(*root)->right)
		return ;
	new_root = (*root)->right;
	new_root->parent = (*root)->parent;
	(*root)->parent = new_root;
	(*root)->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = *root;
	new_root->left = *root;
	*root = new_root;
}
