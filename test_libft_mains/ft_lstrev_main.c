/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:01:05 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 17:09:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*
** usage: head = ft_lstrev(head);
**
** note: on the first run, previous is NULL therefore, lst->next = NULL, the
** first element becomes the very last one.
**
** RETURN: the linked list itself is turned upside down, not a copy.
*/

t_list	*ft_lstrev(t_list *lst)
{
	t_list *tmp;
	t_list *previous;

	if (!lst)
		return (NULL);
	previous = NULL;
	while (lst != NULL)
	{
		tmp = lst->next;
		lst->next = previous;
		previous = lst;
		lst = tmp;
	}
	return (previous);
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", *((int*)head->content));
		head = head->next;
	}
}

int	*malloced_int_ptr(int j)
{
	int *ptr;

	if (!(ptr = (int*)malloc(sizeof(int))))
		return (NULL);
	*ptr = j;
	return (ptr);
}

int	main(void)
{
	t_list *head;
	int *tmp;
	int j;

	head = NULL;
	tmp = NULL;
	j = 0;
	while (j < 20)
	{
		tmp = malloced_int_ptr(j);
		ft_lstadd_back(&head, ft_lstnew(tmp));
		j++;
	}
	print_list(head);
	printf("%p\n", head);
	head = ft_lstrev(head);
	print_list(head);
	printf("%p\n", head);
	return (0);
}
