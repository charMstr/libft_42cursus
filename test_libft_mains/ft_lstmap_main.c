/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:46:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 21:03:09 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: del function is optional. should be NULL if not used.
**
** note2: iteration of f on each link. see ft_lstiter if no copy wanted.
**
** RETURN: copy of lst which is modified according to (*f) function.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;

	new_list = NULL;
	while (lst)
	{
		if (*f)
			ft_lstadd_back(&new_list, ft_lstnew((*f)(lst->content)));
		if (*del)
			(*del)(lst->content);
		lst = lst->next;
	}
	return (new_list);
}

void	display(t_list *lst, int a)
{
	printf("for list %d:\n", a);
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
	;
}

int	main()
{
	t_list *head;
	t_list	*copy;

	char *uno = ft_strdup("uno");
	char *dos = ft_strdup("dos");
	char *tres = ft_strdup("tres");
	char *quatro = ft_strdup("quatro");

	head = ft_lstnew(uno);
	ft_lstadd_back(&head, ft_lstnew(dos));
	ft_lstadd_back(&head, ft_lstnew(tres));
	ft_lstadd_back(&head, ft_lstnew(quatro));
	display(head, 1);

	copy = ft_lstmap(head, func1, NULL);
	display(copy, 2);
	display(head, 1);
	return (0);
}
