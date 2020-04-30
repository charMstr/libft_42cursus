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
	t_list *head2;
	t_list 	*new;
	char	*str;

	head = NULL;
	head2 = NULL;
	str = ft_strdup("7 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	/*
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("5 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("7 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	ft_lstsort(&head, ft_strcmp);
	*/
	print_list(head);

	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);
	str = ft_strdup("6 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);
	str = ft_strdup("5 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);
	ft_lstsort(&head2, ft_strcmp);
	print_list(head2);

	//head = NULL;
	ft_lstmerge(&head, head2, ft_strcmp);
	print_list(head);
	ft_lstclear(&head, free);
	//leaks ok
	//while (1)
	//	;
	return (0);
}
