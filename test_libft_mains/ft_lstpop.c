/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:08:40 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 22:33:42 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstpop(t_list **alst)
{
	t_list *first;

	if (alst && (*alst))
	{
		first = *alst;
		*alst = (*alst)->next;
		if (*first)
		{
			f
		}
		free(first);
	}
}

void	print_listofchar(t_list *head)
{
	t_list *tmp;
	tmp = head;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

int	main()
{
	char *str1 = ft_strdup("hey");
	char *str2 = ft_strdup("salut");
	char *str3 = ft_strdup("how are you?");
	//char *str4 = ft_strdup("doing well today?");
	//char *str5 = ft_strdup("goodbye");


	t_list *head;

	ft_lstadd_back(&head, ft_lstnew(str1));
	ft_lstadd_back(&head, ft_lstnew(str2));
	ft_lstadd_back(&head, ft_lstnew(str3));
	//ft_lstadd_back(&head, ft_lstnew(str4));
	//ft_lstadd_back(&head, ft_lstnew(str5));

	print_listofchar(head);
	printf("\n");
	ft_lstpop(&(head->next));
	print_listofchar(head);

	return (0);
}
