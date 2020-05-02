/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will Return the max depth of the binary tree.
** note:	if the arg is null, the depth is 0, if there is only one node: 1
**
** RETURN:	depth
**			0 if NULL input.
*/

static void	btree_depth_assist(t_btree *node, int *max_depth, int depth)
{
	if (!node)
		return ;
	if (*max_depth < ++depth)
		(*max_depth)++;
	btree_depth_assist(node->left, max_depth, depth);
	btree_depth_assist(node->right, max_depth, depth);
}

int			btree_depth(t_btree *root)
{
	int max_depth;

	max_depth = 0;
	btree_depth_assist(root, &max_depth, 0);
	return (max_depth);
}
