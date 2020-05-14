/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_postorder.c                            :+:      :+:    :+:   */
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
**			browsing is postorder. (first is LEFT, then RIGHT, then ROOT)
*/

int	btree_apply_postorder(t_btree *root, int (*applyf)(void *))
{
	if (root && !btree_apply_postorder(root->left, applyf))
		return (0);
	if (root && !btree_apply_postorder(root->right, applyf))
		return (0);
	if (root && !applyf(root->item))
		return (0);
	return (1);
}
