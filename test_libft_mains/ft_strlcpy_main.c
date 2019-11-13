/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:16:31 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 18:13:39 by charmstr         ###   ########.fr       */
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
	size_t src_len;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (src_len);
	while (i < (dstsize - 1) && i < src_len)
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
	char *src;
	char *dst1;
	char *dst2;

	if (argc != 2)
	{
		printf("failed to provide one arg: the src string\n");
		return (0);
	}
	src = argv[1];
	if (!(dst1 = (char *)malloc(sizeof(char) * 15)))
		return (0);
	if (!(dst2 = (char *)malloc(sizeof(char) * 15)))
		return (0);
	dst1 = memset(dst1, 0, 15);
	dst1 = memset(dst1, 'r', 6);
	dst2 = memset(dst2, 0, 15);
	dst2 = memset(dst2, 'r', 6);

	printf("ft_strlcpy result: %zu\n", ft_strlcpy(dst1, src, 15));
	write(1, dst1, 15);
	printf("\nstrlcpy result: %zu\n", strlcpy(dst2, src, 15));
	write(1, dst2, 15);
	printf("\n");
	return (0);
}
