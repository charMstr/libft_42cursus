/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_apply_postorder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function will apply a callback func to every item of a bstree.
**			browsing is postorder. (first is LEFT, then RIGHT, then ROOT)
*/

int	bstree_apply_postorder(t_bstree *root, int (*applyf)(void *))
{
	if (root && !bstree_apply_postorder(root->left, applyf))
		return (0);
	if (root && !bstree_apply_postorder(root->right, applyf))
		return (0);
	if (root && !applyf(root->item))
		return (0);
	return (1);
}
