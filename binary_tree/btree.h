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

typedef struct	s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	void		*item;
}				t_btree;

void			btree_putchar_fd(char c, int fd);
void			btree_putstr_fd(char *s, int fd);
t_btree			*btree_new(void	*item);
void			btree_add(t_btree **root, t_btree *node, \
			int (*cmp)(void *, void *));
void			btree_debug(t_btree *root, void (*display)());
int				btree_depth(t_btree *root);
void			*btree_find(t_btree *root, void *item_ref, \
			int (*cmp)(void *, void *));
int				btree_apply_prefix(t_btree *root, int (*applyf)(void *));
int				btree_apply_infix(t_btree *root, int (*applyf)(void *));
int				btree_apply_suffix(t_btree *root, int (*applyf)(void *));
int				btree_apply_bfs(t_btree *root, \
			int (*applyf)(void *item, int current_level, int is_first_elem));

#endif
