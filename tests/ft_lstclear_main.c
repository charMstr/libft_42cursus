/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:47:24 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 18:54:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: deletes element and all following ones. different from ft_lstdelone()
**
** note2: if you want to delete from the middle of the list:
** - it puts the pointer to NULL so it ends the list here.
** - 1st arg: &(previous->next) should be used to NULLify the correct pointer
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *previous;

	if (!lst || !(*del))
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		previous = tmp;
		if (!(tmp->content == NULL))
			(*del)(tmp->content);
		tmp = tmp->next;
		free(previous);
		previous = NULL;
	}
	*lst = NULL;
}

void	ft_display(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", (char*)list->content);
		list = list->next;
	}
	printf("\n");
}

void del_func(void *content)
{
	ft_memset((char*)content, 'x', ft_strlen((char*)content));
	printf("%s\n", (char*)content);
	free(content);
	content = NULL;
}

int	main()
{
	t_list *head;
	t_list *tmp;
	t_list *previous;
	char *uno = ft_strdup("uno");
	char *dos = ft_strdup("dos");
	char *tres = ft_strdup("tres");
	char *quatro = ft_strdup("quatro");

	head = ft_lstnew(quatro);
	ft_lstadd_back(&head, ft_lstnew(tres));
	ft_lstadd_back(&head, ft_lstnew(dos));
	ft_lstadd_back(&head, ft_lstnew(uno));
	ft_display(head);

	tmp = head;
	previous = NULL;
	while (tmp != NULL && ft_strncmp((char*)tmp->content, "dos", 6))
	{
		previous = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		printf("failed to find the link\n");
	printf("tmp content: %s\n\n", (char*)tmp->content);
	ft_lstclear(&(previous->next), del_func);
	printf("\n");
	printf("\n%p\n\n", tmp);
	ft_display(head);

	ft_lstclear(&head, NULL);
	ft_display(head);

	return (0);
}
