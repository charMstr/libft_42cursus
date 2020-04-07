/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:27:06 by charmstr          #+#    #+#             */
/*   Updated: 2020/01/30 15:48:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note:	this function will make a duplicate of a two dimensional array.
**
** RETURN:	NULL -> failure in malloc or inside ft_strdup.
**			char **fully copied 2d array.
*/

char	**ft_array_dup(char **array)
{
	char	**copy;
	int		i;
	int		height;

	height = 0;
	i = 0;
	if (!array)
		return (NULL);
	while (array[height])
		height++;
	if (!(copy = (char **)malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	copy[height] = NULL;
	while (i < height)
	{
		if (!(copy[i] = ft_strdup(array[i])))
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

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
	copy = ft_array_dup(tab);
	tab[1][0] = 's';
	tab_display(tab);
	tab_display(copy);
	ft_array_free(tab);
	ft_array_free(copy);
	return (0);
}
