/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:46:48 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 16:57:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: the original is not protected against passing a null pointer as arg
*/

char	*ft_strdup(const char *s1)
{
	size_t i;
	size_t len;
	char *ptr;

	i = 0;
	len = ft_strlen(s1);
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

int	main(int argc, char *argv[])
{
	char *string = "hey boyz how are you doing?";
	char *string2;
	char *string3;

	string2 = NULL;
	string3 = ft_strdup(string);
	printf("string is:\"%s\"\n", string3);
	string3 = strdup(string);
	printf("string is:\"%s\"\n", string3);

	string3 = strdup(string2);
	printf("string is:\"%s\"\n", string3);
	return (0);
}
