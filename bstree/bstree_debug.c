/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:37:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:57:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bstree.h"

/*
** note:	This debugging function will display the bstree in a tree fashion.
**
** note:	The custom display func takes care of displaying the item of a node
**			represented as a string of SIZE_LEAF_DEBUG characters maximum,
**			padded with whitespaces if necessary. If item is null: the leaf is
**			represented as "[null]"...
**
** note:	the define SIZE_LEAF_DEBUG shoud be used by the display func.
**			SIZE_LEAF_DEBUG should be an even number.
**
** note:	Every node is represented by:
**			- either whitespaces if NULL
**			- or between squarred brackets a string representing the item.
*/

/*
**	int	max;		//max depth of the bstree
**	int	current;	//current depth while recursing
**	int	bottom;		//current is trying to reach bottom while doing a bfs.
*/

typedef struct	s_depth
{
	int			max;
	int			current;
	int			bottom;
}				t_depth;

static	void	bstree_debug2(t_bstree *node, t_depth depths, \
		void (*display)())
{
	int	size_line;
	int	i;

	depths.current++;
	i = 0;
	size_line = (1 << (depths.max - depths.current)) * SIZE_LEAF_DEBUG;
	if (!node)
	{
		while (i++ < size_line)
			bstree_putchar_fd(' ', 1);
		return ;
	}
	if (depths.current == depths.bottom)
	{
		while (i++ < (size_line - SIZE_LEAF_DEBUG) / 2)
			bstree_putchar_fd(' ', 1);
		display(node->item);
		while (i++ <= (size_line - SIZE_LEAF_DEBUG))
			bstree_putchar_fd(' ', 1);
		return ;
	}
	bstree_debug2(node->left, depths, display);
	bstree_debug2(node->right, depths, display);
}

void	bstree_debug(t_bstree *root, void (*display)())
{
	t_depth	depths;

	bstree_putstr_fd("\n====================================================="\
			"==========================\n======================= BTREE DEBUG "\
			"START =====================================\n", 1);
	if (root && display)
	{
		depths.max = bstree_depth(root);
		depths.current = 0;
		depths.bottom = 0;
		while (++depths.bottom <= depths.max)
		{
			bstree_debug2(root, depths, display);
			bstree_putchar_fd('\n', 1);
		}
	}
	else
		bstree_putstr_fd("NULL ROOT, or NULL display func\n", 1);
	bstree_putstr_fd("\n============================== DEBUG END ============"\
			"==========================\n===================================="\
			"===========================================\n\n\n", 1);
}
