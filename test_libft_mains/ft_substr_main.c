/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:58:49 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 21:53:15 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: if start > strlen(s) or s is "", returns "" and not NULL
**
** RETURN: pointer on new substring which is len length, NULL if malloc failed
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	src_length;
	size_t	size_malloc;

	if (!s)
		return (NULL);
	src_length = ft_strlen(s);
	i = 0;
	if (start >= src_length)
		size_malloc = 1;
	else if (src_length - start < len)
		size_malloc = src_length - start + 1;
	else
		size_malloc = len + 1;
	if (!(str = (char *)malloc(sizeof(char) * size_malloc)))
		return (NULL);
	while (i < size_malloc - 1)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main()
{
	char *str1 = "0123456789HowYouDoing?";
	char *result;

	result = ft_substr("test", 10, 2);
	printf("%s\n", result);
	ft_putstr_fd(result, 1);
	return (0);
}
