/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:01:24 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 17:01:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

/*
** note: the original unction doesnt protect its pointer arg against NULL case
*/

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char *string = "salut tout le monde!";
	char *pointer = NULL;
	char *string2 = "";
	printf("%lu , %lu\n", ft_strlen(string), strlen(string));
	printf("%lu , %lu\n", ft_strlen(string2), strlen(string2));
	printf("%lu , %lu\n", ft_strlen(string2), strlen(pointer));
	return (0);
}
