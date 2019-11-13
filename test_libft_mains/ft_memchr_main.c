/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:48:43 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 17:29:03 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: segfault if the pointer is a NULL
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return (void *)(s + i);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char *string = "salut les copains!?";
	char *res1;
	char *res2;

	res1 = NULL;
	res2 = NULL;
	res1 = ft_memchr(string, 'a', sizeof(string) - 1);
	res2 = memchr(string, 'a', sizeof(string) - 1);
	printf("res1: %s\n", res1);
	printf("res2: %s\n", res2);
	return (0);
}
