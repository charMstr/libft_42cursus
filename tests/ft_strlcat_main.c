/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 14:26:58 by charmstr         ###   ########.fr       */
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
	while (i < len_dst)
	{
		i++;
	}
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
	memset(dst1, 0, 15);
	memset(dst1, 'r', 6);
	memset(dst2, 0, 15);
	memset(dst2, 'r', 6);

	dst1[0] = '\0';
	dst2[0] = '\0';
	dst1[11] = 'a';
	dst2[11] = 'a';
	printf("strlcat    :%zu\n",strlcat(dst2, src, 15));
	write(1, dst2, 15);
	printf("\nft_strlcat :%zu\n",ft_strlcat(dst1, src, 15));
	write(1, dst1, 15);
	return (0);
}
