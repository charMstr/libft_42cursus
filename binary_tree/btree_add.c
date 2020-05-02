/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will insert a new node in the btree, the insertion
**			position is decided with the cmp function. for each node, if cmp
**			returns a negative value go left, if >= 0 go right.
**
** note:	node is a new node previously malloced. if node->item is null, we
**			exit, so we should not even allow entering the function with a
**			useless node.
**
** note:	cumstom function cmp has a similar behavior to ft_strcmp().
*/

void	btree_add(t_btree **root, t_btree *node, int (*cmp)(void *, void *))
{
	if (!root || !cmp || !node || !node->item)
		return;
	if (!*root)
	{
		*root = node;
		return;
	}
	if (cmp(node->item, (*root)->item) < 0)
		btree_add(&(*root)->left, node , cmp);
	else
		btree_add(&(*root)->right, node , cmp);
}
