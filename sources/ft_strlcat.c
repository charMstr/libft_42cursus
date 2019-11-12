/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:09:21 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 14:33:08 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** /!\ do not use
** only does the job if the <dst> pointer is a string way shorter than its
** allocated memory which is <dstsize>, so that there is enough space for <src>
** string to be added if RETURN is bigger than <dstsize> then it means they
** dont fit .
**
** note: use ft_strjoin instead
**
** note2: ioriginal not protected against NULL inputs arguments
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
