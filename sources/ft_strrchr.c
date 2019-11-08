/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:22:12 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 19:39:26 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: the pointer is not protected in the original function
*/

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int position;

	position = -1;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			position = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	else if (position >= 0)
		return ((char *)(s + position));
	else
		return (NULL);
}
