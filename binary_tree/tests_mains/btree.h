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

struct			s_btree
{
	t_btree		*parent;
	t_btree		*left;
	t_btree		*right;
	void		*item;
};

void			btree_putchar_fd(char c, int fd);
void			btree_putstr_fd(char *s, int fd);
t_btree			*btree_new(void	*item);
void			btree_add(t_btree **root, t_btree *node, \
			int (*cmp)(void *, void *));
void			btree_debug(t_btree *root, void (*display)());
int				btree_depth(t_btree *root);
int				btree_size(t_btree *root);
void			*btree_find(t_btree *root, void *item_ref, \
			int (*cmp)(void *, void *));
t_btree			*btree_get(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *));
int				btree_apply_prefix(t_btree *root, int (*applyf)(void *));
int				btree_apply_infix(t_btree *root, int (*applyf)(void *));
int				btree_apply_suffix(t_btree *root, int (*applyf)(void *));
int				btree_apply_bfs(t_btree *root, \
			int (*applyf)(void *item, int current_level, int is_first_elem));
void			btree_clear(t_btree **root, void (*del)(void*));
void			btree_del(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_make_item_uniq(t_btree **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_make_nodes_uniq(t_btree **root, \
			int (*cmp)(void *, void *), void (*del)(void *));
void			btree_left_rotation(t_btree **root);
void			btree_right_rotation(t_btree **root);

/*
** this next structure is using the enum and implements a red/black tree
** using the same functions as above (except for new, add, del and get) through
** polymorphism.
*/

typedef enum	e_rb_color
{
				RB_BLACK,
				RB_RED
}				t_rb_color;

typedef struct 	s_rb_node t_rb_node;
struct			s_rb_node
{
	t_rb_node	*parent;
	t_rb_node	*left;
	t_rb_node	*right;
	void		*item;
	t_rb_color	color;
};

t_rb_node		*btree_rb_new(void *item);
void			btree_rb_add(t_rb_node **root, t_rb_node *node, \
			int (*cmp)(void *, void *));
void			btree_rb_debug(t_rb_node *root, void (*display)());
int				btree_rb_black_height(t_rb_node *root);
t_rb_node		*btree_rb_get(t_rb_node **root, void *item_ref, \
			int (*cmp)(void *, void *));
void			btree_rb_get_balance(t_rb_node **root, t_rb_node *current,\
			int first_time);
void			btree_rb_delone(t_rb_node **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_rb_del(t_rb_node **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_rb_make_item_uniq(t_rb_node **root, void *item_ref, \
			int (*cmp)(void *, void *), void (*del)(void*));
void			btree_rb_make_nodes_uniq(t_rb_node **root, \
			int (*cmp)(void *, void *), void (*del)(void *));

#endif
