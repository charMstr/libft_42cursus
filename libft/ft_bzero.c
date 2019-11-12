/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:15:50 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 18:02:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** /!\ original not protected  against passing NULL pointer.
**
** RETURN: sets value 0 ta all bytes on n length
*/

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			*((unsigned char *)s + i) = 0;
			i++;
		}
	}
}
