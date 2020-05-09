/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

/*
** note:	this function will free the complete btree from the given root node
**			thanks to the custom free_func().
**
** note:	the del func will have to free the node->item.
*/

void	 btree_clear(t_btree **root, void (*del)(void*))
{
	if (!root || !*root || !del)
		return ;
	btree_clear(&(*root)->left, del);
	btree_clear(&(*root)->right, del);
	del((*root)->item);
	free(*root);
	*root = NULL;
}
