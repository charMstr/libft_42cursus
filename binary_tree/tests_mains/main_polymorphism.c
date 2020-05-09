#include <stdio.h>
#include "btree.h"
#include "libft.h"

typedef enum	e_type
{
	INT,
	STR,
	INT2
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

int	cmp_typeSTR(void *new_item, void *tree_item)
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

	//adding a case that will occur only when removing the
	//node with type == INT from the heterogeneous btree.
	if (new->type == STR && tree->type != STR)
		return (0);
	//leaving the rest as is...
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
		return (ft_strcmp(new->str, tree->str));
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

int	cmp_typeINT(void *new_item, void *tree_item)
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

	//adding a case that will occur only when removing the
	//node with type == INT from the heterogeneous btree.
	if (new->type == INT && tree->type != INT)
		return (0);
	//leaving the rest as is...
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
		return (ft_strcmp(new->str, tree->str));
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
		return (ft_strcmp(new->str, tree->str));
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
	return(btree_rb_new(item));
}

int	creat_item_and_node_and_add(t_rb_node **root, e_type type, char *str, \
		int num, int (*cmp)(void *, void*))
{
	t_rb_node *new_node;

	if (!(new_node = creat_node_with_item(type, str, num)))
		return (0);
	btree_rb_add(root, new_node, cmp);
	return (1);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
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
	if (!(creat_item_and_node_and_add(&root, STR, "Comment", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "D", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "F", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "E", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "HELLO", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, STR, "WORLD", 0, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, 1, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, NULL, 2, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, "blabla", 3, cmp_func)))
		return (0);
	if (!(creat_item_and_node_and_add(&root, INT, "blabla", 42, cmp_func)))
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
	btree_rb_debug(root, display_func);
	item_ref.type = INT;
	subtree = btree_rb_subtree(&root, &item_ref, &item_ref, cmp_typeINT);
	item_ref.type = STR;
	subtree2 = btree_rb_subtree(&subtree, &item_ref, &item_ref, cmp_typeSTR);
	btree_rb_debug(root, display_func);
	btree_rb_debug(subtree, display_func);
	btree_rb_debug(subtree2, display_func);
	return (0);
}
