/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:14:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 23:44:18 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** note: function converts an int to a string of char, according to the base.
**
** note2: the int number parameter should not be more than int_max
**
** note3: if other than base 10, number will be treated as unsigned (positive).
**
** RETURN: NULL or pointer to a string -> will need to be freed.
*/

#include <stdio.h>

#include "libft.h"
#define MAX_BASE 16

static int	predict_size(int num, int base)
{
	int i;

	i = 1;
	if (base == 10 && num < 0)
		i++;
	while (num >= base || num <= -base)
	{
		num = num / base;
		i++;
	}
	return (i);
}

static void	prepare_tab(char tab[][17])
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			(*tab)[i] = i + 48;
		else
			(*tab)[i] = 'A' + i - 10;
		i++;
	}
	tab[0][16] = '\0';
}

char		*ft_itoa_base(int number, int base)
{
	char	*str;
	int		size;
	int		neg;
	char	tab[17];

	prepare_tab(&tab);
	if (base > MAX_BASE || base < 2)
		return (NULL);
	size = predict_size(number, base);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	neg = (base == 10 && number < 0) ? 1 : 0;
	while (--size >= 0)
	{
		str[size] = (number < 0) ? tab[-(number % base)] : tab[number % base];
		number = number / base;
	}
	neg ? str[0] = '-' : 0;
	return (str);
}

int	main(int argc, char *argv[])
{
	char *str;
	if (argc != 3)
	{
		printf("need 2 arguments:\n1/ int\n2/ baseto\n");
		return (0);
	}
	str = ft_itoa_base(atoi(argv[1]), atoi(argv[2]));
	printf("%s\n",str);
	free(str);
	return (0);
}
