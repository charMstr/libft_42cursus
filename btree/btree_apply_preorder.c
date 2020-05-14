/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_preorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this functionn will apply a callback func to every item of a btree.
**			browsing is preorder (ROOT, LEFT then RIGHT)
**
** RETURN:	1 if ok
**			0 if failure in callback function.
*/

int	btree_apply_preorder(t_btree *root, int (*applyf)(void *))
{
	if (root && !applyf(root->item))
		return (0);
	if (root && !btree_apply_preorder(root->left, applyf))
		return (0);
	if (root && !btree_apply_preorder(root->right, applyf))
		return (0);
	return (1);
}
