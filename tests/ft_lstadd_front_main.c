/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 14:41:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: first arg should be the ADDRESS (&...) of an existing link
** or a pointer to a linked list (therefore a t_list ** pointer)
**
** note: the second arg shoud be a call to ft_lstnew(void *content).
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

void	display_linked_list(t_list *alst)
{
	t_list *tmp;

	tmp = alst;
	while (tmp != NULL)
	{
		printf("%d\n", *((int*)tmp->content));
		tmp = tmp->next;
	}
}
int	main()
{
	t_list *head_list;
	int num = 12;
	int num2 = 42;
	int *ptr_num;

	ptr_num = &num;
	head_list = ft_lstnew(ptr_num);
	printf("%d\n", *((int*)head_list->content));
	ft_lstadd_front(&head_list, ft_lstnew(&num2));
	display_linked_list(head_list);
	ft_lstadd_front(NULL, ft_lstnew(&num2));
	return (0);
}
