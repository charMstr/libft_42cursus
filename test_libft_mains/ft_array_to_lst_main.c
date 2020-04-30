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

void	subroutine_for_leaks(void)
{
	t_list	*head;
	char	**array;
	char	**modified;
	char 	*tmp;

	head = NULL;
	array = NULL;
	array = ft_array_add(array, "hey1");
	array = ft_array_add(array, "hey2");
	array = ft_array_add(array, "hey3");
	array = ft_array_add(array, "hey4");
	ft_array_debug(array);
	head = ft_array_to_lst((const char **)array);
	//ok with an array containing a few strings
	print_list(head);
	ft_lstclear(&head, free);
	ft_array_free(&array, ft_array_len((const char **)array));

	//ok with NULL input
	head = ft_array_to_lst(NULL);
	print_list(head);

	//ok with array of only one elemtent
	array = ft_array_add(array, "hey4");
	head = ft_array_to_lst((const char **)array);
	print_list(head);
	ft_array_free(&array, ft_array_len((const char **)array));
	ft_lstclear(&head, free);

	//ok with array with just NULL terminated char **.
	array = malloc(sizeof(char *) * 1);
	array[0] = NULL;
	ft_array_debug(array);
	head = ft_array_to_lst((const char **)array);
	print_list(head);
	ft_array_free(&array, ft_array_len((const char **)array));
	ft_lstclear(&head, free);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	subroutine_for_leaks();
	//leaks ok
	while (1)
		;
	return (0);
}
