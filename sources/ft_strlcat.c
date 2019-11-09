/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 19:18:53 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** /!\ do not use unless you dig the man... do not use
**
** note: use ft_strjoin instead
*/

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
