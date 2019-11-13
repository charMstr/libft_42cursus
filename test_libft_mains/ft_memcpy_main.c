/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:44:56 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 18:49:15 by charmstr         ###   ########.fr       */
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
	if (n != 0 && !dst && !src)
		return (dst);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((const unsigned char *)src + i);
		i++;
	}
	return (dst);
}

int	main()
{
	char *string2 = "hello world!";
	char dest1[13] = {'c'};
	char dest2[13];

	printf("sizeof string1\\2 = %lu\n",sizeof(string2));
	ft_memcpy(NULL, NULL, 1);
	memcpy(NULL, NULL, 10);
	printf("dest2 is: \"%s\"\n",dest2);
	printf("dest1 is: \"%s\"\n",dest1);
	return (0);
}
