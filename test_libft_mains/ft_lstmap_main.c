/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:46:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/15 00:29:58 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	display(t_list *lst, int a)
{
	printf("\nDEBUG list %d:\n", a);
	while (lst)
	{
		printf("%s\n", (char*)lst->content);
		lst = lst->next;
	}
	printf("\n");
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

void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list *head;
	t_list	*copy;
	char *uno;
	char *dos;
	char *tres;
	char *quatro;

	uno = ft_strdup("uno");
	dos = ft_strdup("dos");
	tres = ft_strdup("tres");
	quatro = ft_strdup("quatro");

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(uno));
	ft_lstadd_back(&head, ft_lstnew(dos));
	ft_lstadd_back(&head, ft_lstnew(tres));
	ft_lstadd_back(&head, ft_lstnew(quatro));
	display(head, 1);

	copy = ft_lstmap(head, func1, del);
	display(head, 1);
	display(copy, 2);

	ft_lstclear(&head, free);
	display(head, 1);
	ft_lstclear(&copy, del);
	display(head, 2);
	//leaks ok
	while (1)
		;
	return (0);
}
