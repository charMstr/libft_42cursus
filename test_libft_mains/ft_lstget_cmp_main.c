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
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	print_list(head);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("4 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_cmp(&head, new, ft_strcmp);
	print_list(head);
	new = ft_lstget_cmp(&head, "2 hey", ft_strcmp);
	if (new)
		printf("new->content = [%s]\n", new->content);
	else
		printf("new->content = [%s]\n", NULL);
	ft_lstdelone(new, free);
	print_list(head);
	new = ft_lstget_cmp(&head, "2 hey", ft_strcmp);
	if (new)
		printf("new->content = [%s]\n", new->content);
	else
		printf("new->content = [%s]\n", NULL);
	ft_lstdelone(new, free);
	print_list(head);
	new = ft_lstget_cmp(&head, "2 hey", ft_strcmp);
	if (new)
		printf("new->content = [%s]\n", new->content);
	else
		printf("new->content = [%s]\n", NULL);
	ft_lstdelone(new, free);
	print_list(head);
	new = ft_lstget_cmp(&head, "4 hey", ft_strcmp);
	if (new)
		printf("new->content = [%s]\n", new->content);
	else
		printf("new->content = [%s]\n", NULL);
	ft_lstdelone(new, free);
	print_list(head);
	new = ft_lstget_cmp(&head, "4 hey", ft_strcmp);
	if (new)
		printf("new->content = [%s]\n", new->content);
	else
		printf("new->content = [%s]\n", NULL);
	ft_lstdelone(new, free);
	print_list(head);
	ft_lstclear(&head, free);
	//leaks ok
	//while (1)
		//;
	return (0);
}
