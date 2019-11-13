/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:03:02 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>



size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	while (i < len_dst && i < dstsize)
		i++;
	while (i < dstsize - 1 && (i - len_dst) < len_src)
	{
		*(dst + i) = *(src + i - len_dst);
		i++;
	}
	*(dst + i) = '\0';
	if (len_src + dstsize < len_src + len_dst)
		return (len_src + dstsize);
	else
		return (len_src + len_dst);
}

int	main(int argc, char *argv[])
{
	char *dst1 ;
	char *dst2;

	if (argc != 2)
	{
		printf("failed to provide a src string as argument\n");
		return (0);
	}
	char *src = argv[1];
	if (!(dst1 = (char *)malloc(sizeof(char) * 15)))
		return (0);
	if (!(dst2 = (char *)malloc(sizeof(char) * 15)))
		return (0);

	memset(dst1, 'r', 15);
	//printf("%zu\n",strlcat(dst1, "lorem ipsum dolor sit amet", 5));
	write(1, dst1, 15);

	printf("\n");
	memset(dst2, 'r', 15);
	printf("%zu\n",ft_strlcat(dst2, "lorem ipsum dolor sit amet", 5));
	write(1, dst2, 15);
	return (0);
}
