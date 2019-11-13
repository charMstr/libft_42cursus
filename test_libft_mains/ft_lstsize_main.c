/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:26:57 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/11 14:38:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: arg = the head of the list
**
** RETURN: list's size		or		ZERO if pointer was NULL
*/

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	display_linked_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%d\n", *((int*)list->content));
		list = list->next;
	}
}
int	main()
{
	t_list *head;
	int uno = 1;
	int dos = 2;
	int tres = 3;
	int quatro = 4;

	head = ft_lstnew(&quatro);
	ft_lstadd_front(&head, ft_lstnew(&tres));
	ft_lstadd_front(&head, ft_lstnew(&dos));
	ft_lstadd_front(&head, ft_lstnew(&uno));
	display_linked_list(head);
	printf("%d\n", ft_lstsize(head));
	printf("%d\n", ft_lstsize(NULL));
	return (0);
}
