/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:34:29 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/12 16:22:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** /!\ arguments are not protected against NULL pointers in original
**
** note: characters after a '\0' wont be compared
**
** if you want to make sure both strings are 100% different -->  should be used
** with <n> as ft_strlen(smallest string) + 1
**
** RETURN: no difference -> 0. compares until index (n - 1)
*/


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && (i + 1 < n))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char *argv[])
{
	int i;
	char string[] = "hey yo how are you doi";
	char string2[] = "hey yo how are you do";
	int res1;
	int res2;

	i = 0;
	while (i < ft_strlen(string) + 2)
	{
		res1 =  strncmp(string,string2,i);
		res2 =  ft_strncmp(string,string2,i);
		printf("strncmp Return: %d\n", res1);
		printf("ft_strncmp Return: %d\n", res2);
		printf("index: %d, and char: %c & %c\n",i , string[i], string2[i]);
		if (res1 == res2)
			printf("\033[38;5;2msuccess\n\n\033[m");
		else
		{
			printf("\033[38;5;1mfailed\n\n\033[m");
		}
		i++;
	}
	printf("string size: %zu\ntring2 size : %zu\n", ft_strlen(string) , ft_strlen(string2));
	//strncmp(NULL, string2, 1);
	return (0);
}
