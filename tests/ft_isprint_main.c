/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:30:29 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 18:34:38 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -500;

	while (i < 500)
	{
		if (isprint(i) != ft_isprint(i))
			printf("failed to imitate the behavior of isprint function\n");
		i++;
	}
	return (0);
}
