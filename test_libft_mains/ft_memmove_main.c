/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:13:25 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 18:51:02 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (len != 0 && !dst && !src)
		return (dst);
	while (i < len)
	{
		if (dst > src)
			*((char *)dst + len - i - 1) = *((char *)src + len - i - 1);
		else
			*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}

int	main(int argc, char *argv[])
{
	char string1[] = "salut salut!! hello world!";
	char *dest1;
	char *dest2;
	char *ret1;
	char *ret2;

	printf("sizeof string1 : %lu\n", sizeof(string1));
	if (!(dest1 = (char *)malloc(sizeof(char) * sizeof(string1))))
		return (0);
	if (!(dest2 = (char *)malloc(sizeof(char) * sizeof(string1))))
		return (0);
	ret1 = ft_memmove(string1 + 14, string1, 3);
	printf("ret1 is : \"%s\"\n", ret1);
	ret2 = memmove(string1 + 14, string1, 3);
	printf("ret2 is : \"%s\"\n", ret2);
	return (0);
}
