/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:49:12 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 16:46:01 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: reconnecting the previous and the following link should be done before
** calling this function
**
** note2: therefore content->next is never freed.
**
** note3: the (*del) function shoud be written specific to content
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (!(lst->content == NULL))
		(*del)(lst->content);
	free(lst);
	lst = NULL;
}

void	display(t_list *head)
{
	while (head != NULL)
	{
		printf("%s\n", ((char*)head->content));
		head = head->next;
	}
	printf("\n");
}

void	del_string_content(void *content)
{
	int i;
	int len;

	i = 0;
	// we could free the memory here...
	len = ft_strlen((char*)content);
	while (i < len)
	{
		((char*)content)[i] = 'x';
		i++;
	}
	free(content);
	content = NULL;
}
int	main()
{
	t_list *head;
	char* uno = ft_strdup("uno");
	char* dos = ft_strdup("dos");
	char* tres = ft_strdup("tres");
	char* quatro = ft_strdup("quatro");
	t_list *second;

	head = ft_lstnew(quatro);
	ft_lstadd_back(&head, ft_lstnew(tres));
	ft_lstadd_back(&head, ft_lstnew(dos));
	ft_lstadd_back(&head, ft_lstnew(uno));
	display(head);
	second = head->next;
	display(second);
	ft_lstdelone(head, &del_string_content);
	printf("%s\n", head->content);

	return (0);
}
