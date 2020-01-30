/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:39:20 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:59:42 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note:	this function will make a duplicate of a two dimensional array.
**			all we need to know is its first dimension.
**
** RETURN:	NULL -> failure in malloc or inside ft_strdup.
**			char **fully copied 2d array.
*/

void	tab_display(char **tab)
{
	int i;

	i  =0;
	printf("\n----------tab contains:----------\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("-------end----------\n\n");
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char **tab;
	char **copy;
	int i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (4 + 1))))
		return (0);
	tab[4] = NULL;
	while (i < 4)
	{
		tab[i] = ft_strdup("hey");
		i++;
	}
	tab_display(tab);
	copy = ft_arraydup(tab);
	tab[1][0] = 's';
	tab_display(tab);
	tab_display(copy);
	ft_free_2d(tab);
	ft_free_2d(copy);
	return (0);
}
