/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:34:29 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 22:06:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: characters after a '\0' wont be compared
** note2: arguments are not protected against NULL pointers in original
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *(s2 + i) && *(s1 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	char string[] = "hey yo how are you do";
	char string2[] = "hey yo how are youz do";

	i = 0;
	while (i < 100)
	{
		if (strncmp(string, string2, i) != ft_strncmp(string, string2, i))
		{
			printf("failed to immitate the strncmp fucntion's behavior\n");
			printf("i was : %d\n", i);
		}
		i++;
	}
	//strncmp(NULL, string2, 1);
	return (0);
}
