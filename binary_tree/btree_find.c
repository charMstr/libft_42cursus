/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will return the adress of the first item we meet,
**			while browsing in a dfs infix manner.
**
** note:	we consider the tree should not contain null items... so we return
**			if item_ref is null.
**
** note:	cumstom function cmp has a similar behavior to ft_strcmp().
*/

 void	*btree_find(t_btree *root, void *item_ref, int (*cmp)(void *, void *))
{
	void	*res;

	if (!root || !cmp || !item_ref)
		return (NULL);
	if (!cmp(item_ref, root->item))
		return (root->item);
	if (!(res = btree_find(root->left, item_ref, cmp)))
		res = btree_find(root->right, item_ref, cmp);
	return (res);
}
