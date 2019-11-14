/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:02:30 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 20:50:45 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: arg1: head of list, (ex: &head)	arg2: new link to be added
**
** note2: if *alst is NULL, it means the list was empty. new list is created
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!alst || !new)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	display_list(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", *((int*)head->content));
		head = head->next;
	}
	printf("\n");
}

int	main()
{
	t_list *head;
	int uno = 1;
	int dos = 2;
	int tres = 3;
	int quatro = 4;
	int cinquo = 5;
	t_list *head2;

	head2 = NULL;
	head = ft_lstnew(&quatro);
	ft_lstadd_front(&head, ft_lstnew(&tres));
	ft_lstadd_front(&head, ft_lstnew(&dos));
	ft_lstadd_front(&head, ft_lstnew(&uno));
	display_list(head);
	ft_lstadd_back(&head, ft_lstnew(&cinquo));
	display_list(head);
	ft_lstadd_back(NULL, ft_lstnew(&cinquo));
	ft_lstadd_back(&head2, ft_lstnew(&cinquo));
	display_list(head2);
	return (0);
}
