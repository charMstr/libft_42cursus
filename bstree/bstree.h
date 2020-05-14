/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:37:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:57:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTREE_H
# define BSTREE_H

# include <unistd.h>
# include <stdlib.h>

#define SIZE_LEAF_DEBUG 6

typedef struct	s_bstree t_bstree;

/*
** note:	structure used by basic binary search tree. see t_rb_node for red/
**			black trees.
*/

struct			s_bstree
{
	t_bstree		*parent;
	t_bstree		*left;
	t_bstree		*right;
	void		*item;
};

/*
** note:	this structure is used for the functions that work on ranges.
*/

typedef struct	s_bstree_range
{
	void		*item_ref_min;
	void		*item_ref_max;
}				t_bstree_range;

/*
** debug
*/

void			bstree_debug(t_bstree *root, void (*display)());
void			bstree_putchar_fd(char c, int fd);
void			bstree_putstr_fd(char *s, int fd);

/*
** size
*/

int				bstree_size(t_bstree *root);
int				bstree_depth(t_bstree *root);

/*
** adding
*/

t_bstree			*bstree_new(void	*item);
void			bstree_add(t_bstree **root, t_bstree *node, \
			int (*cmp)(void *, void *));

/*
** deletion
*/

void			bstree_clear(t_bstree **root, void (*del)(void*));
void			bstree_del(t_bstree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			bstree_make_item_uniq(t_bstree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			bstree_make_nodes_uniq(t_bstree **root, \
			int (*cmp)(void *, void *), void (*del)(void *));

/*
** rotation
*/

void			bstree_left_rotation(t_bstree **root);
void			bstree_right_rotation(t_bstree **root);

/*
** searching/getting
*/

void			*bstree_find(t_bstree *root, void *item_ref, \
			int (*cmp)(void *, void *));
t_bstree			*bstree_getnode(t_bstree **root, void *item_ref, \
			int (*cmp)(void *, void *));
t_bstree			*bstree_getnode_range(t_bstree **root, \
			t_bstree_range *range, int (*cmp)(void *, void *));

/*
** apply func
*/

int				bstree_apply_preorder(t_bstree *root, int (*applyf)(void *));
int				bstree_apply_inorder(t_bstree *root, int (*applyf)(void *));
int				bstree_apply_postorder(t_bstree *root, int (*applyf)(void *));
int				bstree_apply_bfs(t_bstree *root, \
			int (*applyf)(void *item, int current_level, int is_first_elem));
int				bstree_apply_range(t_bstree **root, t_bstree_range *range, \
			int (*cmp)(void *, void *), int (*applyf)(void *));

#endif
