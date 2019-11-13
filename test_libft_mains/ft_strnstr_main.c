/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:25:49 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 14:21:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: original function isn't protected against NULL pointer inputs.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
		size_t i;
		size_t j;

		i = 0;
		if (!needle[0])
		{
			return ((char *)haystack);
		}
		while (haystack[i] && (i < len))
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				while ((i + j < len) && haystack[i + j] && needle[j] \
						&& *(haystack + i + j) == *(needle + j))
					j++;
				if (*(needle + j) == '\0')
					return ((char *)(haystack + i));
			}
			i++;
		}
		return (NULL);
}

int	main(int argc, char *argv[])
{
	char *haystack = "hello world, how  how a  ";
	char *needle = "how a";
	char *res1;
	char *res2;

	res1 = ft_strnstr(haystack, needle, ft_strlen(haystack) - 2);
	res2 = strnstr(haystack, needle, ft_strlen(haystack) -1 );

	if (res1 && res2 && ft_strncmp(res1, res2, ft_strlen(res2)))
	{
		printf("failed to imitate the behavior of the strnstr function\n");
		printf("res1: \"%s\"\n", res1);
		printf("res2: \"%s\"\n", res2);
	}
	else if ((res1 && !res2) || (res2 && !res1))
	{
		printf("failed to imitate the behavior of the strnstr function\n");
		printf("res1: \"%s\"\n", res1);
		printf("res2: \"%s\"\n", res2);
	}
	else
	{
		printf("result successful: \"%s\"\n", res2);
		printf("res1: \"%s\"\n", res1);
		printf("res2: \"%s\"\n", res2);
	}
	return (0);
}
