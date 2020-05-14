/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_apply_bfs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

typedef struct	s_apply_bfs
{
	int			*keep_going;
	int			*is_first_elem;
	int			current_level;
	int			bottom;
}				t_apply_bfs;

static int	bstree_apply_bfs2(t_bstree *root, t_apply_bfs bfs, \
		int (*applyf)(void *item, int current_level, int is_first_elem));

/*
** note:	This function will browse the binary tree in a bfs manner, applying
**			the call back function applyf on each node.
** note:	the applyf function takes 3 parameters:
**			- the item in the node.
**			- the level we are at. starting at 0 for root.
**			- is_first_elem contains 1 if this is the very first node for the
**			current_level, 0 elsewise.
**
** note:	the keep_going param is given to the subfunction. if we only met
**			dead_end leafs for the current level keep_going is left to zero.
**			therefor we reached the max depth of the tree.
**
** RETURN:	1 ok
**			0 failure in malloc or NULL inputs (including the very root ptr).
*/

int	bstree_apply_bfs(t_bstree *root, \
		int (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	keep_going;
	int	is_first_elem;
	int res;
	t_apply_bfs	bfs;

	if (!applyf)
		return 0;
	if (!root)
		return (1);
	bfs.bottom = 0;
	bfs.is_first_elem = &is_first_elem;
	bfs.keep_going = &keep_going;
	while (1)
	{
		keep_going = 0;
		bfs.current_level = -1;
		is_first_elem = 1;
		res = bstree_apply_bfs2(root, bfs, applyf);
		if (!*(bfs.keep_going) || !res)
			break;
		bfs.bottom++;
	}
	return (res);
}

/*
** note:	this function will go through the binary tree, level by level as
**			deep as bottom allows it.
**
** RETURN:	1 OK, possible to go deeper or not depending on keep_going.
**			0 KO, some problem occured (malloc failure in applyf).
*/

static int	bstree_apply_bfs2(t_bstree *root, t_apply_bfs bfs, \
		int (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	res;

	if (!root)
		return (1);
	bfs.current_level++;
	if (bfs.current_level == bfs.bottom)
	{
		res = applyf(root->item, bfs.current_level, *(bfs.is_first_elem));
		*(bfs.is_first_elem) = 0;
		if (root->left || root->right)
			*(bfs.keep_going) = 1;
		return (res);
	}
	if ((res = bstree_apply_bfs2(root->left, bfs, applyf)) == 1)
		res = bstree_apply_bfs2(root->right, bfs, applyf);
	return (res);
}
