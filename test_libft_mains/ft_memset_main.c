/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:37:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 17:59:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** /!\ original function not protected against passing NULL pointer
**
** RETURN: pointer in which all bytes is set to the c value
*/

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = c;
		i++;
	}
	return (b);
}

int	main(int argc, char *argv[])
{
	char string[] = "hey how are you";
	int size = sizeof(string);
	ft_memset(string, 'c', sizeof(string));
	printf("size of string is : %lu\n", sizeof(string));
	write(1, &string, size);
	memset(string, 'c', (0));
	return (0);
}
