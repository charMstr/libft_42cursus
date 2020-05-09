#include <stdio.h>
#include "btree.h"
#include "libft.h"

void	display_func(void	*int_ptr)
{
	int	*a;
	int i;
	char *str;

	i = 0;
	a = (int*)int_ptr;
	if (!a)
	{
		ft_putstr_fd("[null]", 1);
		return ;
	}
	str = ft_itoa(*a);
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
	if (*(int*)new_item < *(int*)tree_item)
		return (-1);
	if (*(int*)new_item > *(int*)tree_item)
		return (1);
	return (0);
}

void	free_node(void *node)
{
	node = (void *)node;
	;//free(node);
}

void	check_branches(t_btree *root)
{
	t_btree *current;
	t_btree *copy_root;

	copy_root = root;
	printf("right branchement:\n");
	if (!root)
		return ;
	while (root)
	{
		current = root;
		display_func((int*)(current->item));
		root = root->right;
	}
	printf("\n");
	while (current)
	{
		display_func((int*)(current->item));
		current = current->parent;
	}
	printf("\nleft branchement:\n");
	while (copy_root)
	{
		current = copy_root;
		display_func((int*)(current->item));
		copy_root = copy_root->left;
	}
	printf("\n");
	while (current)
	{
		display_func((int*)(current->item));
		current = current->parent;
	}
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	int		number0 = 0;
	int		number1 = 1;
	int		number2 = 2;
	int		number3 = 3;
	int		number4 = 4;
	int		number5 = 5;
	int		number6 = 6;
	int		number7 = 7;
	int		number8 = 8;
	int		number9 = 9;
	int		number10 = 10;
	int		non_present = 42;
	t_btree *root;
	t_btree *node0;
	t_btree *node1;
	t_btree *node2;
	t_btree *node3;
	t_btree *node30;
	t_btree *node31;
	t_btree *node32;
	t_btree *node4;
	t_btree *node5;
	t_btree *node6;
	t_btree *node70;
	t_btree *node71;
	t_btree *node8;
	t_btree *node9;
	t_btree *node10;
	t_btree *returned;

	root = NULL;
	node0 = btree_new(&number0);
	node1 = btree_new(&number1);
	node2 = btree_new(&number2);
	node3 = btree_new(&number3);
	node4 = btree_new(&number4);
	node5 = btree_new(&number5);
	node6 = btree_new(&number6);
	node70 = btree_new(&number7);
	node71 = btree_new(&number7);
	node8 = btree_new(&number8);
	node9 = btree_new(&number9);
	node10 = btree_new(&number10);
	node30 = btree_new(&number3);
	node31 = btree_new(&number3);
	node32 = btree_new(&number3);
	//real tests
	btree_add(&root, node3, cmp_func);
	btree_debug(root, display_func);
	check_branches(root);
	btree_del(&root, node3->item, cmp_func, free_node);
	btree_debug(root, display_func);
	check_branches(root);
	//removing the only node OK.
	btree_add(&root, node30, cmp_func);
	btree_add(&root, node31, cmp_func);
	btree_debug(root, display_func);
	check_branches(root);
	btree_del(&(root->right), node31->item, cmp_func, free_node);
	btree_debug(root, display_func);
	check_branches(root);
	//removing the right child of the root OK.

	btree_add(&root, node4, cmp_func);
	btree_add(&root, node5, cmp_func);
	btree_debug(root, display_func);
	check_branches(root);
	btree_del(&root, node4->item, cmp_func, free_node);
	btree_debug(root, display_func);
	//removing non-root node when there is only one child. OK

	btree_add(&root, node2, cmp_func);
	btree_debug(root, display_func);
	check_branches(root);
	btree_del(&root, node30->item, cmp_func, free_node);
	btree_debug(root, display_func);
	//removing root with two children OK.

	btree_add(&root, node70, cmp_func);
	btree_add(&root, node9, cmp_func);
	//btree_add(&root, node8, cmp_func);
	btree_add(&root, node10, cmp_func);
	btree_add(&root, node71, cmp_func);
	btree_add(&root, node1, cmp_func);
	btree_add(&root, node6, cmp_func);
	btree_add(&root, node32, cmp_func);
	btree_add(&root, node0, cmp_func);
	btree_add(&root, NULL, cmp_func);
	btree_add(NULL, node0, cmp_func);
	btree_add(&root, node0, NULL);
	btree_debug(root, display_func);
	btree_del(&root, node70->item, cmp_func, free_node);
	btree_debug(root, display_func);
	/*

	btree_debug(root, display_func);
	check_branches(root);
	//removing multiple nodes ok.
	btree_del(&root, &non_present, cmp_func, free_node);
	btree_debug(root, display_func);
	check_branches(root);
	//doing nothing when no match OK
	*/
	/*
	printf("depth is %d\n", btree_depth(root));
	   leaks ok
	while (1)
		;
	*/
	return (0);
}
