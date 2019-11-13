/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:49:05 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 18:53:56 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (tolower(i) != ft_tolower(i))
		{
			printf("for the value:%d\n",i);
			printf("failed to imitate the behavior of tolower function\n");
		}
		i++;
	}
	return (0);
}
