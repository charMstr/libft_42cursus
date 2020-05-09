/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will give the total number of nodes in the btree.
**
** RETURN:	0 the tree is NULL
**			1 or more.
*/

static void	btree_size_assist(t_btree *root, int *size);

int			btree_size(t_btree *root)
{
	int size;

	size = 1;
	if (!root)
		return (0);
	btree_size_assist(root->left, &size);
	btree_size_assist(root->right, &size);
	return (size);
}

static void	btree_size_assist(t_btree *root, int *size)
{
	if (!root)
		return ;
	(*size)++;
	btree_size_assist(root->left, size);
	btree_size_assist(root->right, size);
}
