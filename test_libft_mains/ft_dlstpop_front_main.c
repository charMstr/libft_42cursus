#include "../libft/libft.h"
#include <stdio.h>

void	display_lst_to_next(t_dlist *lst)
{
	int i;

	if (!lst)
		return ;
	i = 0;
	printf("\n----------------------------------------------------------------\n");
	printf("DEBUG: going towards NEXT\n");
	while (lst)
	{
		printf("[%d]lst->content = [%s]\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

void	display_lst_to_previous(t_dlist *lst)
{
	int i;

	if (!lst)
		return ;
	i = 0;
	printf("\n----------------------------------------------------------------\n");
	printf("DEBUG: going towards PREVIOUS\n");
	while (lst)
	{
		printf("[%d]lst->content = [%s]\n", i, (char *)lst->content);
		lst = lst->previous;
		i++;
	}
}

void	del_content(void *content)
{
	free((char*)content);
}

void debug_link(t_dlist *lst)
{
	if (!lst)
	{
		printf("link is NULL\n");
		return ;
	}
	printf("link: [%p]\n", lst);
	printf("link->next: [%p]\n", lst->next);
	printf("link->previous: [%p]\n", lst->previous);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_dlist *head;
	t_dlist *new;
	t_dlist *some_link;
	t_dlist *last;
	char *str1 = ft_strdup("1HEY");
	char *str2 = ft_strdup("2HEY");
	char *str3 = ft_strdup("3HEY");
	char *str4 = ft_strdup("4HEY");
	char *str5 = ft_strdup("5HEY");
	char *str6 = ft_strdup("6HEY");
	char *str7 = ft_strdup("7HEY");

	head = NULL;
	if (!(new = ft_dlstnew((void*)str3)))
	{
		printf("failed to creat link\n");
		return (0);
	}
	ft_dlstadd_front(&head, new);
	new = ft_dlstnew((void*)str2);
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str4);
	//saving a random link in the middle
	some_link = new;
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str1);
	ft_dlstadd_front(&head, new);
	new = ft_dlstnew((void*)str5);
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str6);
	ft_dlstadd_back(&head, new);
	printf("debugging from the start:\n");
	display_lst_to_previous(head);
	display_lst_to_next(head);
	printf("\nNOW debugging from a link in the middle:\n");
	display_lst_to_previous(some_link);
	display_lst_to_next(some_link);

	printf("NOW DELETING THE FIRST LINK in a loop (starting from head)\n");
	while (head)
	{
		display_lst_to_next(head);
		ft_dlstpop_front(&head, del_content);
	}
	ft_dlstpop_front(&head, del_content);
	ft_dlstpop_front(&head, del_content);
	new = ft_dlstnew((void*)str7);
	ft_dlstadd_front(&head, new);
	display_lst_to_next(head);
	ft_dlstpop_front(&head, del_content);
	ft_dlstpop_front(&head, del_content);
	return (0);
}
