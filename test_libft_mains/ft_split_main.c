/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:26:50 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 23:03:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>

/*
** note: use of malloc, and free
**
** RETURN: the array of strings separated by c, or NULL if malloc failed or if
** empty string
*/


int	main(int argc, char *argv[])
{
	char *string;
	char **ptr;
	int i;
	char c;

	if (argc != 3)
	{
		printf("failed to povide 2 arg: string to be split, and separator char\n");
		return (0);
	}
	string = argv[1];
	c = argv[2][0];

	printf("assertions for null inputs...ok\n");
	assert(ft_split(NULL, c) == NULL);

	i = 0;
	printf("original string: [%s]\n",string);
	printf("ans splitting char: [%c]\n", c);
	printf("\n");
	ptr = ft_split(string, c);
	while (ptr[i])
	{
		printf("[%s]\n", ptr[i]);
		i++;
	}
	ft_array_free(&ptr, ft_array_len((const char **)ptr));
	return (0);
}
