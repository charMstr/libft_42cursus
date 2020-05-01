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

void	func1(void *content)
{
	char *str;
	int	i;

	str = (char*)content;
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}


int	ft_cmp2char(char *str1, char *str2)
{
	if (ft_strncmp(str1, str2, 2) == 0)
		return (0);
	return (1);
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
	str = ft_strdup("2 heyi   iisxoXo");
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
	str = ft_strdup("2 heyo");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	str = ft_strdup("2HHoooo");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	print_list(head);
	ft_lstiter_cmp(head, func1, ft_cmp2char, "2 ");
	print_list(head);
	ft_lstclear(&head, free);
	str = ft_strdup("2HHoooo");
	new = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	ft_lstiter_cmp(NULL, func1, ft_cmp2char, "2 ");
	print_list(head);
	ft_lstiter_cmp(head, NULL, ft_cmp2char, "2 ");
	print_list(head);
	ft_lstiter_cmp(head, func1, NULL, "2 ");
	print_list(head);
	ft_lstiter_cmp(head, func1, ft_cmp2char, NULL);
	print_list(head);
	ft_lstclear(&head, free);
	//leaks ok
	while (1)
		;
	return (0);
}
