/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:44:56 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 16:46:45 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
/*
** use ft_memmove instead as the overlapping of memory areas result in an
** undefined behavior
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}


/*
** the original function does segfault when both src or dst pointers are NULL.
*/

int	main(int argc, char *argv[])
{
	char *string1 =  NULL;
	char *string2 = "hello world!";
	char dest1[13];
	char dest2[13];

	printf("sizeof string1\\2 = %lu\n",sizeof(string1));
	ft_memcpy(dest1, string1, 13);
	memcpy(dest2, string2, 13);
	printf("dest2 is: \"%s\"\n",dest2);
	printf("dest1 is: \"%s\"\n",dest1);
	return (0);
}
