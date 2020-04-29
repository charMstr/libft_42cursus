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
	//works on an empty list.
	ft_lstdel_cmp(&head, "2 hey", ft_strcmp, free);

	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	ft_lstdel_cmp(&head, "2 hey", ft_strcmp, free);
	ft_lstdel_cmp(&head, "2 hey", ft_strcmp, free);
	//worked when there is only one element

	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstdel_cmp(&head, "2 hey", ft_strcmp, free);
	print_list(head);
	ft_lstclear(&head, free);
	//ok

	//now build a list with 3 times the thing we want to delete
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstdel_cmp(&head, "2 hey", ft_strcmp, free);
	print_list(head);
	//leaks ok
	//while (1)
	//	;
	return (0);
}
