/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:23 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 15:00:50 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** RETURN: pointer to very last link, NULL if the head of list pointer was NULL
**
** /!\ always make sure the result is not NULL
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *previous;

	previous = NULL;
	while (lst != NULL)
	{
		previous = lst;
		lst = lst->next;
	}
	return (previous);
}

int	main()
{
	t_list *head;
	t_list *last;
	int uno = 1;
	int dos = 2;
	int tres = 3;
	int quatro = 4;

	head = ft_lstnew(&quatro);
	ft_lstadd_front(&head, ft_lstnew(&tres));
	ft_lstadd_front(&head, ft_lstnew(&dos));
	ft_lstadd_front(&head, ft_lstnew(&uno));
	last = ft_lstlast(NULL);
	printf("%p\n", last);
	//printf("%d\n", *((int*)last->content));
	return (0);
}

