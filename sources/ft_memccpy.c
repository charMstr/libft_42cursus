/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:14:36 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 16:44:41 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the function still copies the character c if encountered then returns a
** pointer to the folowing byte.
** /!\ the src and dst should not overlap.
** note: if pointers are NULL: segfault results in the original function
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if ((unsigned char)c == *((unsigned char *)src + i))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
