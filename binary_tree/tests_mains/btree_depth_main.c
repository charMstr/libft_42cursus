#include <stdio.h>
#include <assert.h>
#include "btree.h"

void	display_func(int *a)
{
	printf("[%d]\n", *a);
}

/*
** note:	this debugging function will display whatever is in the btree,
**			using the display function for the item
*/

void	btree_debug(t_btree *root, void (*display)())
{
	if (!root)
	{
		printf("[NULL leaf]\n");
		return ;
	}
	btree_debug(root->left, display);
	display(root->item);
	btree_debug(root->right, display);
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
	t_btree *node1;
	t_btree *node2;
	t_btree *node3;
	t_btree *node4;
	t_btree *node5;
	t_btree *node6;
	t_btree *node7;
	int		depth;

	root = NULL;
	assert(0== btree_depth(root));
	root = btree_new(&number0);
	assert(1 == btree_depth(root));
	node1 = btree_new(&number1);
	root->left = node1;
	assert(2 == btree_depth(root));
	node2 = btree_new(&number2);
	node1->left = node2;
	assert(3 == btree_depth(root));
	node3 = btree_new(&number3);
	node1->right = node3;
	assert(3 == btree_depth(root));
	node4 = btree_new(&number4);
	root->right = node4;
	assert(3 == btree_depth(root));
	node5 = btree_new(&number5);
	node4->left = node5;
	assert(3 == btree_depth(root));
	node6 = btree_new(&number6);
	node4->right = node6;
	assert(3 == btree_depth(root));
	node7 = btree_new(&number7);
	node6->left = node7;
	assert(4 == btree_depth(root));
	btree_debug(root, display_func);
	//OK
	return (0);
}
