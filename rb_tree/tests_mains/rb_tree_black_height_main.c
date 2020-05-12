#include <stdio.h>
#include "rb_tree.h"
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
	if (!new_item || !tree_item)
		return (1);
	if (*(int*)new_item < *(int*)tree_item)
		return (-1);
	if (*(int*)new_item > *(int*)tree_item)
		return (1);
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
	t_rb_node *root;
	t_rb_node *node0;
	t_rb_node *node1;
	t_rb_node *node2;
	t_rb_node *node3;
	t_rb_node *node4;
	t_rb_node *node5;
	t_rb_node *node6;
	t_rb_node *node7;
	t_rb_node *null_item0;
	t_rb_node *null_item1;
	t_rb_node *null_item2;

	root = NULL;
	node0 = rb_tree_new(&number0);
	node1 = rb_tree_new(&number1);
	node2 = rb_tree_new(&number2);
	node3 = rb_tree_new(&number3);
	node4 = rb_tree_new(&number4);
	node5 = rb_tree_new(&number5);
	node6 = rb_tree_new(&number6);
	node7 = rb_tree_new(&number7);
	null_item0 = rb_tree_new(NULL);
	null_item1 = rb_tree_new(NULL);
	null_item2 = rb_tree_new(NULL);

	//real tests
	rb_tree_add(&root, node3, cmp_func);
	node2->color = RB_BLACK;
	rb_tree_add(&root, node2, cmp_func);
//	node0->color = RB_BLACK;
//	rb_tree_add(&root, node0, cmp_func);
	rb_tree_add(&root, node7, cmp_func);
	node5->color = RB_BLACK;
	rb_tree_add(&root, node5, cmp_func);
	rb_tree_add(&root, node6, cmp_func);
	rb_tree_add(&root, node4, cmp_func);
	rb_tree_debug(root, display_func);
	null_item0->color = RB_BLACK;
	rb_tree_add(&root, null_item0, cmp_func);
	rb_tree_add(&root, null_item1, cmp_func);
	rb_tree_debug(root, display_func);
	printf("\nBLACK_HEIGHT: %d\n", rb_tree_black_height(root));
	//rb_tree_add(&root, null_item2, cmp_func);
	//rb_tree_add(&root, node1, cmp_func);

	printf("\ndepth is %d\n", rb_tree_depth(root));
	return (0);
}
