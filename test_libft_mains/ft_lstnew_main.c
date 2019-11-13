/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:50:59 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 18:32:17 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: next = NULL, content = the argument
** note2: if content is NULL it doesnt mather it is still created as is.
**
** RETURN: new link that was malloced, or NULL pointer if malloc failed.
*/

t_list	*ft_lstnew(void *content)
{
	t_list *ptr_new_link;

	if (!(ptr_new_link = malloc(sizeof(t_list))))
		return (NULL);
	ptr_new_link->content = content;
	ptr_new_link->next = NULL;
	return (ptr_new_link);
}

int	main()
{
	char *string = "hey salut";
	int *ptr;
	int num;
	t_list *new;
	t_list *new2;

	ptr = &num;
	*ptr = 65;

	new = ft_lstnew(NULL);
	new->content = string;
	printf("%s\n", (char*)new->content);
	printf("sizeof t_list : %zu\n", sizeof(t_list));
	new2 = ft_lstnew(ptr);
	printf("%d\n",*((int*)new2->content));
	printf("%c\n", *((char*)new2->content));
	return (0);
}

