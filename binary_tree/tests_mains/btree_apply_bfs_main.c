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
	printf("\nnew_item = %d\n", *(int*)new_item);
	printf("tree_item = %d\n\n", *(int*)tree_item);
	if (*(int*)new_item < *(int*)tree_item)
		return (-1);
	if (*(int*)new_item == *(int*)tree_item)
		return (0);
	return (1);
}

int	applyf(void *item, int current_level, int is_first_elem)
{
	int *content;

	content = (int*)item;
	if (current_level % 2)
		*content += 100;
	if (is_first_elem)
		*content *= -1;
	return (1);
}

int	applyf2(void *item, int current_level, int is_first_elem)
{
	int *content;

	content = (int*)item;
	if (current_level % 2)
		*content += 100;
	if (is_first_elem)
		*content *= -1;
	return (0);
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
	t_btree *node3;
	t_btree *node4;
	t_btree *node5;
	t_btree *node6;
	t_btree *node7;

	root = NULL;
	node0 = btree_new(&number0);
	node1 = btree_new(&number1);
	node2 = btree_new(&number2);
	node3 = btree_new(&number3);
	node4 = btree_new(&number4);
	node5 = btree_new(&number5);
	node6 = btree_new(&number6);
	node7 = btree_new(&number7);
	//real tests
	btree_add(&root, node3, cmp_func);
	//ok if there is only one node
	//printf("==> %d\n", btree_apply_bfs(root, applyf));
	btree_debug(root, display_func);
	//
	btree_add(&root, node1, cmp_func);
	printf("==> %d\n", btree_apply_bfs(root, applyf));
	btree_debug(root, display_func);
	btree_add(&root, node5, cmp_func);
	btree_add(&root, node4, cmp_func);
	btree_add(&root, node7, cmp_func);
	btree_add(&root, node6, cmp_func);
	btree_add(&root, node2, cmp_func);
	//btree_add(&root, node0, cmp_func);

	btree_debug(root, display_func);
	//ok with null inputs, it only returns zero in the case applyf is null
	printf("==> %d\n", btree_apply_bfs(NULL, applyf));
	btree_debug(root, display_func);
	printf("==> %d\n", btree_apply_bfs(root, NULL));
	btree_debug(root, display_func);
	// ok
	printf("==> %d\n", btree_apply_bfs(root, applyf));
	btree_debug(root, display_func);
	// ok if func fails, it returns zero
	printf("==> %d\n", btree_apply_bfs(root, applyf2));
	btree_debug(root, display_func);
	return (0);
}
