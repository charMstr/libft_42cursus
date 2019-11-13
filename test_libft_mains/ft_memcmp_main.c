/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:22:27 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 16:38:24 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char *string1 = "salut tOut le monde";
	char *string2 = "salut tOut le monde";
	int res1;
	int res2;

	res1 = ft_memcmp(string1, string2, ft_strlen(string2));
	res2 = memcmp(string1, NULL, ft_strlen(string2));
	printf("res1: %d\n", res1);
	printf("res2: %d\n", res2);
	return (0);
}
