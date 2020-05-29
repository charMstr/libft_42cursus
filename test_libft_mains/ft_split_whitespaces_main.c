/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
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
	char *ifs;
	char **ptr;
	int i;

	if (argc != 3)
	{
		printf("failed to povide 2 arg: string to be split, and separator str\n");
		return (0);
	}
	string = argv[1];
	ifs = argv[2];

	printf("assertions for null inputs...ok\n");
	assert(ft_split_whitespaces(NULL, ifs) == NULL);
	assert(ft_split_whitespaces(string, NULL) == NULL);

	i = 0;
	printf("original string: [%s]\n",string);
	printf("ans splitting ifs string: [%s]\n", ifs);
	printf("\n");
	ptr = ft_split_whitespaces(string, ifs);
	while (ptr[i])
	{
		printf("[%s]\n", ptr[i]);
		i++;
	}
	ft_array_free(&ptr, ft_array_len((const char **)ptr));
	return (0);
}
