#include <stdio.h>
#include "bstree.h"
#include "rb_tree.h"
#include "libft.h"

/*
**	This mains use some polymorphism to implement a red/black tree with node
**	that can hold defferent types of data. The job is up to the custon cmp
**	function when it comes to creat an order between the different type of
**	things.
**	And when the things are of the same kind, then a sub cmp function will help
**	us be more discriminant.
**
** note:	when you want to do a subtree that takes one kind of the tree and
**			place it in a subtree.2 ways to implement it:
**
**			1) add an extra enum in the label, and name it something that means
**			its only here to remove the node (example: ECTRACT). When calling
**			the btree_rb_subtree() func with twice the same dummy item_ref,
**			this will remove the nodes only if you add the following condition
**			in the custom cmp function:
**				if (new->type == EXTRACTINT && tree->type == INT)
**					return (0);
**				if (new->type == EXTRACTINT)
**					return (1);
**			note: the advantage with this solution is that you can use the
**			same function. the condition is met only when the dummy node is
**			passed on, and at removal time! But it requires 2 if statements and
**			a dedicated enum by type you want to potentially remove.
**
**			1) Basically think of it the other way: take
**			out everything thay is not that kind and move it into the new
**			subtree. therefor the current tree contains only that kind.
**			This can be acchived by copy pasting the same cmp function. But
**			adding near the begining a condition returning 0 when the
**			item_ref->type provided is what we want to isolate, but the
**			item_in_tree->type is not. Therefor this if statement is entered
**			only at node extraction time. When the extracted node is added to
**			the tree containing what we dont want, it is in place of iterm_ref,
**			the if statement is never met, and the rest of the cmp function
**			does the rest of the balancing.
**
**			example, add this statement.
**				if (item_ref->type == STR && item_in_tree->type != STR)
**					return (0);
**
*/

typedef enum	e_type
{
	INT,
	RM_INT,
	STR,
	RM_STR,
	INT2,
	RM_INT2
}				e_type;

typedef struct	s_items
{
	e_type	type;
	char	*str;
	int		num;
}				t_items;

void	display_str(char *str)
{
	int i;

	i = 0;
	ft_putchar_fd('[', 1);
	while (i < (SIZE_LEAF_DEBUG - 2) && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	while (i++ < SIZE_LEAF_DEBUG - 2)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd(']', 1);
}

void	display_int(int num)
{
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

void	display_func(void	*item)
{
	t_items *it;

	it = (t_items*)item;
	if (!it)
	{
		ft_putstr_fd("[null]", 1);
		return ;
	}
	if (it->type == STR)
	{
		ft_putstr_fd("\033[35m", 1);
		display_str(it->str);
	}
	else
	{
		if (it->type == INT)
			ft_putstr_fd("\033[36m", 1);
		if (it->type == INT2)
			ft_putstr_fd("\033[32m", 1);
		display_int(it->num);
	}
	ft_putstr_fd("\033[0m", 1);
}

int	cmp_func(void *new_item, void *tree_item)
{
	t_items *new;
	t_items *tree;

	new = (t_items*)new_item;
	tree = (t_items*)tree_item;
	if (!new_item && !tree_item)
		return (0);
	if (!new_item)
		return (1);
	if (!tree_item)
		return (-1);

	//extraction closes for the subtree func.
	if (new->type == RM_INT && tree->type == INT)
		return (0);
	if (new->type == RM_STR && tree->type == STR)
		return (0);
	if (new->type == RM_INT2 && tree->type == INT2)
		return (0);
	if (new->type == RM_INT || new->type == RM_INT2 || new->type == RM_STR)
		return (1);

	//INT < INT2 && INT2 < STR
	if (new->type == INT && tree->type == INT2)
		return (-1);
	if (new->type == INT2 && tree->type == INT)
		return (1);

	if (new->type == INT && tree->type == STR)
		return (-1);
	if (new->type == STR && tree->type == INT)
		return (1);

	if (new->type == INT2 && tree->type == STR)
		return (-1);
	if (new->type == STR && tree->type == INT2)
		return (1);

	if (new->type == STR && tree->type == STR)
	{
		if (!new->str || !tree->str)
			return (42);
		return (ft_strcmp(new->str, tree->str));
	}
	else if (new->type == INT && tree->type == INT)
	{
		if (new->num < tree->num)
			return (-1);
		if (new->num > tree->num)
			return (1);
		return (0);
	}
	else if (new->type == INT2 && tree->type == INT2)
	{
		if (new->num < tree->num)
			return (-1);
		if (new->num > tree->num)
			return (1);
		return (0);
	}
	return (0);
}

void	free_func(void *item)
{
	t_items *it;

	it = (t_items*)item;
	if (it->type == STR)
		free(it->str);
	free(it);
}

t_items *creat_item(e_type type, char *str, int num)
{
	t_items *new;

	if (!(new = malloc(sizeof(t_items))))
		return (NULL);
	new->str = NULL;
	new->num = 0;
	new->type = type;
	if (type == STR)
	{
		if (!str || !(new->str = ft_strdup(str)))
		{
			free(new);
			return (NULL);
		}
	}
	else if (type == INT)
		new->num = num;
	else if (type == INT2)
		new->num = num;
	return (new);
}

t_rb_node *creat_node_with_item(e_type type, char *str, int num)
{
	t_items *item;

	item = creat_item(type, str, num);
	if (!item)
		return (NULL);
	return(rb_tree_new(item));
}

int	creat_item_and_node_and_add(t_rb_node **root, e_type type, char *str, \
		int num, int (*cmp)(void *, void*))
{
	t_rb_node *new_node;

	if (!(new_node = creat_node_with_item(type, str, num)))
		return (0);
	rb_tree_add(root, new_node, cmp);
	return (1);
}

int	main_assist(void)
{
	t_rb_node *root;
	t_rb_node *subtree;
	t_rb_node *subtree2;
	t_rb_node *node;
	t_items  item_ref;

	root = NULL;
	subtree = NULL;
	subtree2 = NULL;
	if (!(creat_item_and_node_and_add(&root, STR, "A", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "B", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 16, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 16, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 16, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "Comment", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "charlie", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "Xarlie", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, 1, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, 2, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, "blabla", 3, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, "blabla", 42, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "E", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "HELLO", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "HELLO", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "WORLD", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, "blabla", 16, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 16, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 142, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 100, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 101, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, "blabla", 102, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "42", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "Bonjour", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "communique", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "haha", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "hehe", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "hoho", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "xoxo", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "yoppp", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "coca", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "cola", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, 123213124, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, 88813124, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, 1789, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, -1789, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -1789, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -1788, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -1787, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -1786, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -42, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -41, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -40, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -39, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, -35, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, 666, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, 444, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT2, NULL, 555, cmp_func)))
		return (0);

	printf("root contains:\n");
	rb_tree_debug(root, display_func);

	printf("after making all nodes->item uniq, root contains:\n");
	rb_tree_make_nodes_uniq(&root, cmp_func, free_func);
	rb_tree_debug(root, display_func);

	void *item_ref2;

	printf("searching for the green it containing 102:\n");
	item_ref.type = INT2;
	item_ref.num = 102;
	if ((item_ref2 = bstree_find((t_bstree*)root, (void *)&item_ref, cmp_func)))
	{
		printf("item_ref was found!\n");
		display_func(item_ref2);
	}

	//creating a range structure.
	t_rb_tree_range range;
	range.item_ref_min = &item_ref;
	range.item_ref_max = &item_ref2;

	item_ref.type = RM_INT;
	printf("\n\nbuilding a subtree, extracting only the cyan nodes (ints) from the tree:\n");
	while ((node = rb_tree_getnode_range(&root, &range, cmp_func)))
	{
		rb_tree_add(&subtree, node, cmp_func);
	}
	rb_tree_debug(subtree, display_func);

	item_ref.type = RM_STR;
	printf("building a subtree, extracting only the purple nodes (strings) from the tree:\n");
	while ((node = rb_tree_getnode_range(&root, &range, cmp_func)))
	{
		rb_tree_add(&subtree2, node, cmp_func);
	}
	rb_tree_debug(subtree2, display_func);

	printf("now the root contains whatever is left:\n");
	rb_tree_debug(root, display_func);


	//cleaning memory
	bstree_clear((t_bstree**)&root, free_func);
	bstree_clear((t_bstree**)&subtree, free_func);
	bstree_clear((t_bstree**)&subtree2, free_func);
	return (0);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	main_assist();
	/* leaks ok
	while (1)
		;
		*/
	return (0);
}
