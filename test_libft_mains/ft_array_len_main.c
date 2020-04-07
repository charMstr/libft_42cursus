/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:27:06 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:48:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>

/*
** note:	this function will return the length of a two dimension chararray
**
** RETURN:	-1 if array itself is NULL
**			0 the first string was NULL
**			>0 for the number of substrings non NULL
*/

int	ft_array_len(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char **null_array = NULL;
	char **empty_array;
	char **array;
	const char *array_static[] = (const char *[]){"hello", "world", "ca", "va?", NULL};


	assert(ft_array_len(null_array) == -1);
	if (!(empty_array = malloc(sizeof(char *) * 1)))
	{
		printf("failure in creating an empty array\n");
		return (0);
	}
	empty_array[0] = NULL;
	assert(ft_array_len(empty_array) == 0);

	if (!(array = malloc(sizeof(char *) * 3)))
	{
		printf("failure in malloc\n");
		return (0);
	}
	array[0] = ft_strdup("hey");
	array[1] = ft_strdup("haeee");
	array[2] = NULL;
	assert(ft_array_len(array) == 2);
	printf("OK, every thing fine\n");

	printf("now the next assert should fail\n");
	assert(ft_array_len((char **)array_static) == 3);
	/*
	printf("now the next assert should fail\n");
	assert(ft_array_len(array) == 3);
	*/
	return (0);
}
