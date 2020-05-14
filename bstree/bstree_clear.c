/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	this function will free the complete bstree from the given root
**			node thanks to the custom free_func().
**
** note:	the del func will have to free the node->item.
*/

void	 bstree_clear(t_bstree **root, void (*del)(void*))
{
	if (!root || !*root || !del)
		return ;
	bstree_clear(&(*root)->left, del);
	bstree_clear(&(*root)->right, del);
	del((*root)->item);
	free(*root);
	*root = NULL;
}
