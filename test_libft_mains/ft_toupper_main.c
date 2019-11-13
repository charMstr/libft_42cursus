/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:35:39 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 18:48:21 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (toupper(i) != ft_toupper(i))
		{
			printf("%d\n", i);
			printf("failed to immitate the behavior of toupper function\n");
		}
		i++;
	}
	return (0);
}
