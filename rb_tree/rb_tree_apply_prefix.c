/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_apply_prefix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

/*
** note:	this functionn will apply a callback func to every item of a
**			rb_tree. Browsing is prefix first.
**
** RETURN:	1 ok
**			something failed in the callback function.
*/

int	rb_tree_apply_prefix(t_rb_node *root, int (*applyf)(void *))
{
	if (root && !rb_tree_apply_prefix(root->left, applyf))
		return (0);
	if (root && !applyf(root->item))
		return (0);
	if (root && !rb_tree_apply_prefix(root->right, applyf))
		return (0);
	return (1);
}
