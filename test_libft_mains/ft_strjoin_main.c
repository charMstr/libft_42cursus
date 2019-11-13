/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:07:18 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 19:22:19 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** RETURN: pointer on s1 + s2 (concatenation), or NULL if malloc failed, or one
** of the two arguments is a NULL pointer
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	size_t len1;
	size_t len2;
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * len1 + len2 + 1)))
		return (NULL);
	while (i < len1)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	while (i < len1 + len2)
	{
		*(ptr + i) = *(s2 + i - len1);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

int	main(int argc, char *argv[])
{
	char *ptr1 = "hey salut,";
	char *ptr2 = "sa va comme tu veux?";
	char *ptr3;

	ptr3 = ft_strjoin(ptr1, ptr2);
	printf("%s\n", ptr3);
	return (0);
}
