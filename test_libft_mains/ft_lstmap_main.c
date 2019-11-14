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

/*
** note: iteration of (*f) on each link. see ft_lstiter if no copy wanted.
**
** note2: (*del) is passed to ft_lstclear to clean the whole new_list if a
** malloc failed in ft_lstnew.
**
** RETURN: copy of lst which is modified according to (*f) function. The RETURN
** can be NULL if lst is NULL or if failure mallocing midway
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_link;

	new_list = NULL;
	while (lst)
	{
		if (*f)
			new_link = ft_lstnew((*f)(lst->content));
		if (!new_link && (*del))
		{
			ft_lstclear(&new_list,(*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_link);
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
	content = (void *)content;
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

	copy = ft_lstmap(head, func1, del);
	display(copy, 2);
	display(head, 1);
	return (0);
}
