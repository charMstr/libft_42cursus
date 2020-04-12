#include "../libft/libft.h"
#include <stdio.h>

void	free_links_content(void *stra)
{
	char *str;

	str = (char *)stra;
	free(str);
}

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
	t_dlist *get;
	t_dlist *some_link;
	t_dlist *some_link2;
	char *str1 = ft_strdup("1HEY");
	char *str2 = ft_strdup("2HEY");
	char *str3 = ft_strdup("3HEY");
	char *str4 = ft_strdup("4HEY");
	char *str5 = ft_strdup("5HEY");

	head = NULL;
	if (!(new = ft_dlstnew((void*)str1)))
	{
		printf("failed to creat link\n");
		return (0);
	}
	ft_dlstadd_front(&head, new);
	new = ft_dlstnew((void*)str2);
	ft_dlstadd_front(&head, new);
	new = ft_dlstnew((void*)str3);
	//store a random link from the middle
	some_link = new;
	some_link2 = new;
	ft_dlstadd_front(&head, new);
	new = ft_dlstnew((void*)str4);
	ft_dlstadd_front(&head, new);
	printf("debugging from the start:\n");
	display_lst_to_previous(head);
	display_lst_to_next(head);
	printf("\nNOW debugging from a link in the middle:\n");
	display_lst_to_previous(some_link);
	display_lst_to_next(some_link);

	printf("\n\n----OK-----\n"\
			"now adding a link from an adress in the middle of the l-list\n");
	new = ft_dlstnew((void*)str5);
	ft_dlstadd_front(&some_link, new);
	printf("debugging from the start:\n");
	display_lst_to_previous(head);
	display_lst_to_next(head);
	printf("\nNOW debugging from a link in the middle:\n");
	display_lst_to_previous(some_link);
	display_lst_to_next(some_link);
	printf("\n\ngetting the very first link:\n");
	get = ft_dlstfirst(some_link);
	printf("in first link: string is: [%s]\n", (char*)get->content);
	printf("\n\ngetting the very last link:\n");
	get = ft_dlstlast(some_link);
	printf("in last link: string is: [%s]\n", (char*)get->content);
	printf("link in the middle from wich we start clearing contains:"\
			"[%s]\n", (char*)some_link2->content);
	ft_dlstclear(&some_link2, free_links_content);
	while (1)
		;
	return (0);
}

