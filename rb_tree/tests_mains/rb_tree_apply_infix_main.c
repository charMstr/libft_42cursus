#include <stdio.h>
#include "rb_tree.h"
#include "libft.h"

int glob = 0;

int	display_func(void	*int_ptr)
{
	int	*a;
	int i;
	char *str;

	glob++;
	if (glob == 6)
	{
		printf("escape!\n");
		return (0);
	}
	i = 0;
	a = (int*)int_ptr;
	if (!a)
	{
		ft_putstr_fd("[null]", 1);
		return (1);
	}
	if (!(str = ft_itoa(*a)))
		return (0);
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
	return (1);
}

void	 display_func_debug(void	*int_ptr)
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
	if (!(str = ft_itoa(*a)))
		return ;
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
	t_rb_node *node1;
	t_rb_node *node2;
	t_rb_node *node3;
	t_rb_node *node4;
	t_rb_node *node5;
	t_rb_node *node6;
	t_rb_node *node7;
	int res;

	root = rb_tree_new(&number0);
	node1 = rb_tree_new(&number1);
	root->left = node1;
	node2 = rb_tree_new(&number2);
	node1->left = node2;
	node3 = rb_tree_new(&number3);
	node1->right = node3;
	node4 = rb_tree_new(&number4);
	root->right = node4;
	node5 = rb_tree_new(&number5);
	node4->left = node5;
	node6 = rb_tree_new(&number6);
	node4->right = node6;
	node7 = rb_tree_new(&number7);
	node6->left = node7;

	rb_tree_debug(root, display_func_debug);
	res = rb_tree_apply_infix(root, display_func);
	printf("res is %d\n", res);
	printf("depth is %d\n", rb_tree_depth(root));
	return (0);
}
