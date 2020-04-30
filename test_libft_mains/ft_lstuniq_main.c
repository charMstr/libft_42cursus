#include <stdio.h>
#include "libft.h"

void	print_list(t_list *head)
{
	printf("\nDEBUG of LST:\n");
	if (!head)
	{
		printf("empty list\n");
		return ;
	}
	while (head)
	{
		printf("[%s]\n", head->content);
		head = head->next;
	}
	printf("END DEBUG\n\n");
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_list *head;
	t_list 	*new;
	char	*str;

	head = NULL;
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstuniq(&head, ft_strcmp, free);
	print_list(head);
	ft_lstclear(&head, free);
	//now uniq a list of one elem
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstuniq(&head, ft_strcmp, free);
	print_list(head);
	//now uniq a list of 2 elems
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstuniq(&head, ft_strcmp, free);
	print_list(head);
	ft_lstclear(&head, free);
	//now uniq on a list of NULL
	ft_lstuniq(NULL, ft_strcmp, free);
	//leaks ok
	//while (1)
		//;
	return (0);
}
