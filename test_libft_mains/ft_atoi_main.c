/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:22:17 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 14:31:15 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int nb;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') ||\
			(str[i] == '\f') || (str[i] == ' ') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (int)(nb * sign);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("failed to provide a single arg\n");
		return (0);
	}
	printf("%d\n", atoi(argv[1]));
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
