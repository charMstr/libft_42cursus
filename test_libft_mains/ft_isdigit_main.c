/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:22:00 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 17:31:36 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -100;
	while (i < 1000)
	{
		if (isdigit(i) != ft_isdigit(i))
		{
			printf("%d\n", i);
			printf("failed to imitate the behavior of the isdigit function\n");
		}
		i++;
	}
	printf("%d\n", isdigit(450 + 256));
	return (0);
}
