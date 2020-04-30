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

void	print_dlist(t_dlist *head)
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

void	*func1(void *content)
{
	char *string;
	size_t i;

	i = 0;
	string = ft_strdup((char*)content);
	while (i < ft_strlen(string))
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
	return ((void *)string);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_list *head;
	t_dlist *dhead;
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
	dhead = ft_lst_to_dlst(head, func1, free);
	print_dlist(dhead);
	ft_lstclear(&head, free);
	ft_dlstclear(&dhead, free);
	//leaks ok
	while (1)
		;
	return (0);
}

