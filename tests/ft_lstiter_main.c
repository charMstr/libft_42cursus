/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 19:45:22 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: iteration of f function on every CONTENTS of every links of the list
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!(*f))
		return ;
	while (lst)
	{
		if (!(lst->content == NULL))
			(*f)(lst->content);
		lst = lst->next;
	}
}

void	display(t_list *ptr)
{
	while (ptr)
	{
		printf("%s\n", (char*)ptr->content);
		ptr = ptr->next;
	}
	printf("\n");
}

void	del(void *content)
{
	size_t i;

	i = 0;
	while (i < ft_strlen((char*)content))
	{
		((char*)content)[i] = ft_toupper(((char*)content)[i]);
		i++;
	}
}

int	main()
{
	t_list *head;
	char *uno = ft_strdup("uno");
	char *dos = ft_strdup("dos");
	char *tres = ft_strdup("tres");
	char *quatro = ft_strdup("quatro");

	head = ft_lstnew(quatro);
	ft_lstadd_front(&head, ft_lstnew(tres));
	ft_lstadd_front(&head, ft_lstnew(dos));
	ft_lstadd_front(&head, ft_lstnew(uno));
	display(head);
	ft_lstiter(NULL, del);
	display(head);

	return (0);
}
