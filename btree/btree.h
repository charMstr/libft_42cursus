/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:37:31 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:57:52 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <unistd.h>
# include <stdlib.h>

#define SIZE_LEAF_DEBUG 6

typedef struct	s_btree t_btree;

/*
** note:	structure used by basic binary search tree. see t_rb_node for red/
**			black trees.
*/

struct			s_btree
{
	t_btree		*parent;
	t_btree		*left;
	t_btree		*right;
	void		*item;
};

/*
** note:	this structure is used for the functions that work on ranges.
*/

typedef struct	s_btree_range
{
	void		*item_ref_min;
	void		*item_ref_max;
}				t_btree_range;

/*
** debug
*/

void			btree_debug(t_btree *root, void (*display)());
void			btree_putchar_fd(char c, int fd);
void			btree_putstr_fd(char *s, int fd);

/*
** size
*/

int				btree_size(t_btree *root);
int				btree_depth(t_btree *root);

/*
** adding
*/

t_btree			*btree_new(void	*item);
void			btree_add(t_btree **root, t_btree *node, \
			int (*cmp)(void *, void *));

/*
** deletion
*/

void			btree_clear(t_btree **root, void (*del)(void*));
void			btree_del(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_make_item_uniq(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_make_nodes_uniq(t_btree **root, \
			int (*cmp)(void *, void *), void (*del)(void *));

/*
** rotation
*/

void			btree_left_rotation(t_btree **root);
void			btree_right_rotation(t_btree **root);

/*
** searching/getting
*/

void			*btree_find(t_btree *root, void *item_ref, \
			int (*cmp)(void *, void *));
t_btree			*btree_getnode(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *));
t_btree			*btree_getnode_range(t_btree **root, t_btree_range *range, \
			int (*cmp)(void *, void *));

/*
** apply func
*/

int				btree_apply_prefix(t_btree *root, int (*applyf)(void *));
int				btree_apply_infix(t_btree *root, int (*applyf)(void *));
int				btree_apply_suffix(t_btree *root, int (*applyf)(void *));
int				btree_apply_bfs(t_btree *root, \
			int (*applyf)(void *item, int current_level, int is_first_elem));
int				btree_apply_range(t_btree **root, t_btree_range *range, \
			int (*cmp)(void *, void *), int (*applyf)(void *));

#endif
