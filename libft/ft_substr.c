/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:58:49 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 18:52:55 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: if start position falls outside s string, returns NULL
** note2: comparing start + len and lenght of s -> shortest malloc possible.
**
** RETURN: pointer on new substring which is len length, NULL if malloc failed
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	src_length;

	if (!s)
		return (NULL);
	src_length = ft_strlen(s);
	i = 0;
	if (start >= src_length)
		return (NULL);
	if (src_length - start < len)
	{
		if (!(str = (char *)malloc(sizeof(char) * (src_length - start + 1))))
			return (NULL);
	}
	else if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(s + start + i) && i < len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
