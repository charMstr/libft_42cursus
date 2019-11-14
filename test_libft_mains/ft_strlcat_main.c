/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 17:56:07 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;
	size_t src_len;

	i = 0;
	k = 0;
	src_len = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[src_len])
		src_len++;
	if (!dstsize)
		return (i + src_len);
	while (src[k] && (i + k < dstsize - 1))
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i + k <= dstsize - 1)
		dst[i + k] = '\0';
	return (i + src_len);
}

int	main(int argc, char *argv[])
{
	char *dst1 ;
	char *dst2;
	char *src;
	int dst_size;

	if (argc != 3)
	{
		printf("failed to provide a src string as argument, and destsize\n");
		return (0);
	}
	src = argv[1];
	dst_size = atoi(argv[2]);
	if (!(dst1 = (char *)malloc(sizeof(char) * dst_size)))
		return (0);
	if (!(dst2 = (char *)malloc(sizeof(char) * dst_size)))
		return (0);
	memset(dst1, 0, dst_size);
	memset(dst2, 0, dst_size);
	memset(dst1, 'r', 6);
	memset(dst2, 'r', 6);

	printf("\nft_str...:%zu",ft_strlcat(dst1, src, dst_size));
	write(1, "\n", 1);
	write(1, dst1, 15);
	write(1, "\n", 1);
	printf("str...:%zu",strlcat(dst2, src, dst_size));
	write(1, "\n", 1);
	write(1, dst2, 15);
	write(1, "\n", 1);

	memset(dst1, 0, dst_size);
	memset(dst2, 0, dst_size);
	memset(dst1, 'r', 6);
	memset(dst2, 'r', 6);

	dst1[14] = 'a';
	dst2[14] = 'a';
	printf("\nft_str...:%zu\n",ft_strlcat(dst1, src, dst_size));
	write(1, dst1, 15);
	printf("\nstr...:%zu\n",strlcat(dst2, src, dst_size));
	write(1, dst2, 15);
}
