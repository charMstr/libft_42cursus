/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:16:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 21:53:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** returns the length of the string it tried to create,i therefore: strlen(src)
** note: undefined behavior if strings overlap
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i < (dstsize - 1))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

int	main(int argc, char *argv[])
{
	int i;
	char *src = "hello world!";
	char *dst1;
	char *dst2;
	int len;

	len = strlen(src);
	if (!(dst1 = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (!(dst2 = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	dst1 = strcpy(dst1, "hey");
	dst2 = strcpy(dst2, "hey");

	printf("dst1 is :\"%s\"\n", dst1);
	printf("dst2 is :\"%s\"\n", dst2);
	printf("ft_strlcpy return:%lu\n",ft_strlcpy(dst1, src, 0));
	printf("dst1 is now: \"%s\"\n", dst1);
	printf("strlcpy return:%lu\n",strlcpy(dst2, src, 0));
	printf("dst2 is now: \"%s\"\n", dst2);

	i = 0;
	while (i < len)
	{
		ft_strlcpy(dst1, src, i);
		strlcpy(dst2, src, i);
		if (strcmp(dst1, dst2))
		{
			printf("failed to immitate the behavior of strlcpy function\n");
		}
		i++;
	}
	return (0);
}
