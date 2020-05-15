/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_back_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:08:40 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 22:28:45 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_listofchar(t_list *head)
{
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
}

int	main()
{
	char *str1 = ft_strdup("hey");
	char *str2 = ft_strdup("salut");
	char *str3 = ft_strdup("how are you?");
	char *str4 = ft_strdup("doing well today?");
	char *str5 = ft_strdup("goodbye");


	t_list *head;
	t_list *back;

	ft_lstadd_back(&head, ft_lstnew(str1));
	ft_lstadd_back(&head, ft_lstnew(str2));
	ft_lstadd_back(&head, ft_lstnew(str3));
	ft_lstadd_back(&head, ft_lstnew(str4));
	ft_lstadd_back(&head, ft_lstnew(str5));

	printf("the linked list contains:\n");
	print_listofchar(head);
	back = ft_lstget_back(&head);
	printf("\n");
	printf("now that we poped the back the linked list contains:\n");
	print_listofchar(head);
	printf("the poped link contains:\n");
	print_listofchar(back);

	printf("\n\n\033[34mdoing it it until we poped nothing:\033[0m\n");
	while (head)
	{
		printf("now that we poped the back the linked list contains:\n");
		print_listofchar(head);
		back = ft_lstget_back(&head);
		printf("the poped link contains:\n");
		print_listofchar(back);
	}
	printf("\n\n\033[34mwhen done:\033[0m\n");
	printf("now that we poped the back the linked list contains:\n");
	print_listofchar(head);
	printf("the poped link contains:\n");
	print_listofchar(back);

	return (0);
}

