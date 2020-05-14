/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function will creat a new node. and place item in it.
**
** return:	NULL if malloc failed
**			new node ptr
*/

t_bstree			*bstree_new(void	*item)
{
	t_bstree	*new;

	if (!(new = (t_bstree*)malloc(sizeof(t_bstree))))
		return NULL;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->item = item;
	return (new);
}
