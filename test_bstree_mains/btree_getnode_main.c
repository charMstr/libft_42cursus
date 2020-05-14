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
	if (!new_item && !tree_item)
		return (0);
	if (!new_item)
		return (1);
	if (!tree_item)
		return (-1);
	if (*(int*)new_item < *(int*)tree_item)
		return (-1);
	if (*(int*)new_item > *(int*)tree_item)
		return (1);
	return (0);
}

void	check_branches(t_btree *root)
{
	t_btree *current;
	t_btree *copy_root;

	copy_root = root;
	printf("right branchement:\n");
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
	t_btree *root;
	t_btree *node0;
	t_btree *node1;
	t_btree *node2;
	t_btree *node30;
	t_btree *node31;
	t_btree *node32;
	t_btree *node4;
	t_btree *node5;
	t_btree *node6;
	t_btree *node7;
	t_btree *null_item0;
	t_btree *null_item1;
	t_btree *null_item2;

	root = NULL;
	node0 = btree_new(&number0);
	node1 = btree_new(&number1);
	node2 = btree_new(&number2);
	node30 = btree_new(&number3);
	node31 = btree_new(&number3);
	node32 = btree_new(&number3);
	node4 = btree_new(&number4);
	node5 = btree_new(&number5);
	node6 = btree_new(&number6);
	node7 = btree_new(&number7);
	null_item0 = btree_new(NULL);
	null_item1 = btree_new(NULL);
	null_item2 = btree_new(NULL);

	btree_add(&root, node5, cmp_func);
	btree_add(&root, node4, cmp_func);
	btree_add(&root, null_item1, cmp_func);
	btree_add(&root, node7, cmp_func);
	btree_add(&root, node6, cmp_func);
	btree_add(&root, null_item2, cmp_func);
	btree_add(&root, node2, cmp_func);
	btree_add(&root, node0, cmp_func);
	btree_add(&root, node1, cmp_func);
	btree_add(&root, node30, cmp_func);
	btree_add(&root, node31, cmp_func);
	btree_add(&root, node32, cmp_func);

	btree_debug(root, display_func);
	t_btree *node;
	t_btree *subtree;
	subtree = NULL;

	node = btree_getnode(&root, node30->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));

	node = btree_getnode(&root, node0->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));

	node = btree_getnode(&root, node4->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));

	node = btree_getnode(&root, node5->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));
	node = btree_getnode(&root, node30->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));
	node = btree_getnode(&root, node1->item, cmp_func);
	btree_debug(root, display_func);
	printf("ptr contains:%d \n", *(int*)(node->item));

	printf("now getting whatever is left over into a  new_subtree\n");
	while (root && (node = btree_getnode(&root, root->item, cmp_func)))
	{
		btree_add(&subtree, node, cmp_func);
	}
	btree_debug(subtree, display_func);
	printf("depth is %d\n", btree_depth(root));
	return (0);
}
