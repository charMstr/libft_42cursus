#include <stdio.h>
#include <assert.h>
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
	int		depth;

	root = NULL;
	assert(0== rb_tree_depth(root));
	root = rb_tree_new(&number0);
	assert(1 == rb_tree_depth(root));
	node1 = rb_tree_new(&number1);
	root->left = node1;
	assert(2 == rb_tree_depth(root));
	node2 = rb_tree_new(&number2);
	node1->left = node2;
	assert(3 == rb_tree_depth(root));
	node3 = rb_tree_new(&number3);
	node1->right = node3;
	assert(3 == rb_tree_depth(root));
	node4 = rb_tree_new(&number4);
	root->right = node4;
	assert(3 == rb_tree_depth(root));
	node5 = rb_tree_new(&number5);
	node4->left = node5;
	assert(3 == rb_tree_depth(root));
	node6 = rb_tree_new(&number6);
	node4->right = node6;
	assert(3 == rb_tree_depth(root));
	node7 = rb_tree_new(&number7);
	node6->left = node7;
	assert(4 == rb_tree_depth(root));
	rb_tree_debug(root, display_func);
	//OK
	return (0);
}
