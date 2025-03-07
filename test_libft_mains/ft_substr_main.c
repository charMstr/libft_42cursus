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
** note:	if the len parameter is bigger than the length of str we will stop
**			at the end of str.
** note:	if start > strlen(s) or s is empty, returns an empty string.:w
** note:	the length of the substring: min(len, strlen(str +  start)).
**
** some examples:
**		str1:[0123456789HowYouDoing?]
**		absolute position of char '3' is: 3
**
**		do the call ft_substr(str1, start=0, 3);
**		now printing the substring: [012]
**
**		do the call ft_substr(str1, 3, ft_strlen(str1) - 3);
**		now printing the substring2: [3456789HowYouDoing?]
**
**		do the call ft_substr(str1, 0, ft_strlen(str1) - 1);
**		now printing the substring3: [0123456789HowYouDoing]
**
** RETURN:	pointer on new substring
**			NULL if malloc failed
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
	char *substr;
	char *substr2;
	char *substr3;
	int position;

	printf("str1:[%s]\n", str1);
	position = ft_strichr(str1, '3');
	printf("absolute position of char '3' is: %d\n", position);
	printf("\ndo the call ft_substr(str1, start=0, 3);\n");
	substr = ft_substr(str1, 0, position);
	printf("now printing the substring: [%s]\n", substr);
	printf("\ndo the call ft_substr(str1, 3, ft_strlen(str1) - 3);\n");
	substr2 = ft_substr(str1, 3, ft_strlen(str1) - 3);
	printf("now printing the substring2: [%s]\n", substr2);
	printf("\ndo the call ft_substr(str1, 0, ft_strlen(str1) - 1);\n");
	substr3 = ft_substr(str1, 0, ft_strlen(str1) - 1);
	printf("now printing the substring3: [%s]\n", substr3);

	return (0);
}
