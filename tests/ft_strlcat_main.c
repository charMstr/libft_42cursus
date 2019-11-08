/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 23:28:13 by charmstr         ###   ########.fr       */
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
	while (i < dstsize - 1)
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
	char *dst1;
	char *dst2;
	char *src = "RAJ";
	int i;

	if (!(dst1 = (char *)malloc(sizeof(char) * 30)))
		return (0);
	if (!(dst2 = (char *)malloc(sizeof(char) * 30)))
		return (0);
	dst1 = strcpy(dst1, "salut!");
	dst2 = strcpy(dst2, "salut!");
	printf("strlcat    :%zu\n",strlcat(dst2, src, 4));//strlen(src) + strlen(dst2) + 1 ));
	printf("dest2 is: \"%s\"\n", dst2);
	printf("ft_strlcat :%zu\n",ft_strlcat(dst1, src, 4));//strlen(src) + strlen(dst1) + 1 ));
	printf("dest1 is: \"%s\"\n", dst1);
	return (0);
}
