/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_red_black_and_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 01:27:04 by charmstr          #+#    #+#             */
/*   Updated: 2021/06/10 02:35:04 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "rb_tree.h"
#include "bstree.h"
#include "libft.h"

void	display_int(void *item)
{
	int *item_int;
	item_int = (int*)item;
	int num = *item_int;
	int i;
	char *str;

	i = 0;
	str = ft_itoa(num);
	ft_putchar_fd('[', 1);
	while (i < (SIZE_LEAF_DEBUG - 2) && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (i++ < SIZE_LEAF_DEBUG - 2)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd(']', 1);
	free(str);
}


int	cmp_func(void *new_item, void *tree_item)
{
	int *new;
	int	*tree;
	new = (int*)new_item;
	tree = (int*)tree_item;
	return (*new - *tree);
	if (*new < *tree) return (-1);
	if (*new > *tree) return (1);
	else  return (0);
}

void	free_func(void *item)
{
	int *it;
	free(it);
}

t_rb_node *create_node(int num)
{
	int *new;

	if (!(new = malloc(sizeof(int))))
		return (NULL);
	*new = num;
	return(rb_tree_new(new));
}

int	create_node_and_add(t_rb_node **root, int num, int (*cmp)(void *, void*))
{
	t_rb_node *new_node;

	if (!(new_node = create_node(num)))
		return (0);
	printf("new_node.content = %d\n", *(int*)(new_node->item));
	rb_tree_add(root, new_node, cmp);
	return (1);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	t_rb_node *root;

	root = NULL;
	create_node_and_add(&root, 3, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 10, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 11, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 12, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 20, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 6, cmp_func);
	rb_tree_debug(root, display_int);
	create_node_and_add(&root, 7, cmp_func);
	create_node_and_add(&root, 8, cmp_func);
	create_node_and_add(&root, 9, cmp_func);
	create_node_and_add(&root, 33, cmp_func);
	create_node_and_add(&root, 34, cmp_func);
	create_node_and_add(&root, 35, cmp_func);
	create_node_and_add(&root, 36, cmp_func);
	rb_tree_debug(root, display_int);
	return (0);
}
