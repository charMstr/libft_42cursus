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

void	debug_content3(t_rb_node **node)
{
	setbuf(stdout, NULL);
	printf("\nnode's address: %p\n", *node);
	printf("node's  parent: %p\n", (*node)->parent);
	printf("node's   right: %p\n", (*node)->right);
	printf("node's    left: %p\n", (*node)->left);
	printf("node's 	  item: %d\n", *(int*)((*node)->item));
	if ((*node)->color == RB_RED)
		printf("node's 	  color: \033[31mRED\033[0m\n");
	else
		printf("node's 	  color: BLACK\n");
}

void	free_func(void *item)
{
	(void)item;
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
	int		number11 = 11;
	int		number12 = 12;
	int		number13 = 13;
	int		number14 = 14;
	int		number15 = 15;
	int		number16 = 16;
	int		number17 = 17;
	int		number18 = 18;
	int		number19 = 19;
	int		number20 = 20;
	int		number21 = 21;
	t_rb_node *root;
	t_rb_node *node0;
	t_rb_node *node1;
	t_rb_node *node2;
	t_rb_node *node30;
	t_rb_node *node31;
	t_rb_node *node32;
	t_rb_node *node33;
	t_rb_node *node34;
	t_rb_node *node40;
	t_rb_node *node41;
	t_rb_node *node42;
	t_rb_node *node43;
	t_rb_node *node44;
	t_rb_node *node45;
	t_rb_node *node5;
	t_rb_node *node6;
	t_rb_node *node7;
	t_rb_node *node8;
	t_rb_node *node9;
	t_rb_node *node10;
	t_rb_node *node11;
	t_rb_node *node12;
	t_rb_node *node13;
	t_rb_node *node14;
	t_rb_node *node15;
	t_rb_node *node16;
	t_rb_node *node17;
	t_rb_node *node18;
	t_rb_node *node19;
	t_rb_node *node20;
	t_rb_node *node21;
	t_rb_node *null_item0;
	t_rb_node *null_item1;
	t_rb_node *null_item2;

	root = NULL;
	node0 = rb_tree_new(&number0);
	node1 = rb_tree_new(&number1);
	node2 = rb_tree_new(&number2);
	node30 = rb_tree_new(&number3);
	node31 = rb_tree_new(&number3);
	node32 = rb_tree_new(&number3);
	node33 = rb_tree_new(&number3);
	node34 = rb_tree_new(&number3);
	node40 = rb_tree_new(&number4);
	node41 = rb_tree_new(&number4);
	node42 = rb_tree_new(&number4);
	node43 = rb_tree_new(&number4);
	node44 = rb_tree_new(&number4);
	node45 = rb_tree_new(&number4);
	node5 = rb_tree_new(&number5);
	node6 = rb_tree_new(&number6);
	node7 = rb_tree_new(&number7);
	node8 = rb_tree_new(&number8);
	node9 = rb_tree_new(&number9);
	node10 = rb_tree_new(&number10);
	node11 = rb_tree_new(&number11);
	node12 = rb_tree_new(&number12);
	node13 = rb_tree_new(&number13);
	node14 = rb_tree_new(&number14);
	node15 = rb_tree_new(&number15);
	node16 = rb_tree_new(&number16);
	node17 = rb_tree_new(&number17);
	node18 = rb_tree_new(&number18);
	node19 = rb_tree_new(&number19);
	node20 = rb_tree_new(&number20);
	node21 = rb_tree_new(&number21);
	null_item0 = rb_tree_new(NULL);
	null_item1 = rb_tree_new(NULL);
	null_item2 = rb_tree_new(NULL);
	//real tests
	rb_tree_add(&root, node2, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node30, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node40, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node5, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node6, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, null_item1, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, null_item2, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node31, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node32, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, null_item0, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node1, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node7, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node8, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node0, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node9, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node33, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node34, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node41, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node42, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node43, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node44, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node10, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node11, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node12, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node13, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node14, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node15, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node16, cmp_func);
	rb_tree_debug(root, display_func);
	//celui qui fait tout planter!
	//need a fix from here.
	rb_tree_add(&root, node17, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node18, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node19, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node20, cmp_func);
	rb_tree_debug(root, display_func);
	rb_tree_add(&root, node21, cmp_func);
	rb_tree_debug(root, display_func);
	printf("rb_tree size : %d\n", rb_tree_size(root));
	printf("making uniq the number 4.\n");
	rb_tree_make_item_uniq(&root, &number4, cmp_func, free_func);
	rb_tree_debug(root, display_func);
	printf("making uniq the number 3.\n");
	rb_tree_make_item_uniq(&root, &number3, cmp_func, free_func);
	rb_tree_debug(root, display_func);
	/*
	if (!rb_tree_black_height(root))
		printf("height is fucked up\n");
	*/
	return (0);
}
