#include "../libft/libft.h"
#include <stdio.h>

void	display_lst_to_next(t_dlist *lst)
{
	int i;

	if (!lst)
		return ;
	i = 0;
	printf("\n\n----------------------------------------------------------------\n");
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
	printf("\n\n----------------------------------------------------------------\n");
	printf("DEBUG: going towards PREVIOUS\n");
	while (lst)
	{
		printf("[%d]lst->content = [%s]\n", i, (char *)lst->content);
		lst = lst->previous;
		i++;
	}
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_dlist *head;
	t_dlist *new;
	t_dlist *some_link;
	char *str1 = "1HEY";
	char *str2 = "2HEY";
	char *str3 = "3HEY";
	char *str4 = "4HEY";
	char *str5 = "5HEY";

	head = NULL;
	if (!(new = ft_dlstnew((void*)str1)))
	{
		printf("failed to creat link\n");
		return (0);
	}
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str2);
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str3);
	//store a random link from the middle
	some_link = new;
	ft_dlstadd_back(&head, new);
	new = ft_dlstnew((void*)str4);
	ft_dlstadd_back(&head, new);
	printf("debugging from the start:\n");
	display_lst_to_previous(head);
	display_lst_to_next(head);
	printf("\nNOW debugging from a link in the middle:\n");
	display_lst_to_previous(some_link);
	display_lst_to_next(some_link);

	printf("\n\n----OK-----\n"\
			"now adding a link from an adress in the middle of the l-list\n");
	new = ft_dlstnew((void*)str5);
	ft_dlstadd_back(&some_link, new);
	printf("debugging from the start:\n");
	display_lst_to_previous(head);
	display_lst_to_next(head);
	printf("\nNOW debugging from a link in the middle:\n");
	display_lst_to_previous(some_link);
	display_lst_to_next(some_link);
	return (0);
}
