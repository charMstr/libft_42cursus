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
	t_list *head1;
	t_list *head2;
	t_list *head3;
	t_list 	*new;
	t_list	*last;
	int		res;
	char	*str;

	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	//ok with NULL input
	res = ft_lstloop_proof(NULL);


	//ok with only one element
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head1, new);

	last = ft_lstlast(head1);
	last->next = head1;
	res = ft_lstloop_proof(head1);
	printf("\n\nhead1 is infinite loop proof? %d\n", res);
	ft_lstclear(&head1, free);
	print_list(head1);


	//ok with two element
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head2, new);

	last = ft_lstlast(head2);
	last->next = head2;
	res = ft_lstloop_proof(head2);
	printf("\n\nhead2 is infinite loop proof? %d\n", res);
	ft_lstclear(&head2, free);
	print_list(head2);


	//ok with three elements
	str = ft_strdup("1 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head3, new);
	str = ft_strdup("2 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head3, new);
	str = ft_strdup("3 hey");
	new = ft_lstnew(str);
	ft_lstadd_back(&head3, new);
	print_list(head3);

	last = ft_lstlast(head3);
	last->next = head3;
	res = ft_lstloop_proof(head3);
	printf("head3 is infinite loop proof? %d\n", res);
	ft_lstclear(&head3, free);
	printf("head after delete: [%p]\n", head3);


	//OK

	//leaks ok
	//while (1)
		//;
	return (0);
}
