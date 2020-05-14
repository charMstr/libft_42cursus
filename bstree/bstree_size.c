/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function will give the total number of nodes in the bstree.
**
** RETURN:	0 the tree is NULL
**			1 or more.
*/

static void	bstree_size_assist(t_bstree *root, int *size);

int			bstree_size(t_bstree *root)
{
	int size;

	size = 1;
	if (!root)
		return (0);
	bstree_size_assist(root->left, &size);
	bstree_size_assist(root->right, &size);
	return (size);
}

static void	bstree_size_assist(t_bstree *root, int *size)
{
	if (!root)
		return ;
	(*size)++;
	bstree_size_assist(root->left, size);
	bstree_size_assist(root->right, size);
}
