/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:14:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 17:39:13 by charmstr         ###   ########.fr       */
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

static void	prepare_symbols_array(char *symb_array, int base)
{
	int i;

	i = -1;
	while (i < base)
	{
		if (i < 10)
			symb_array[i] = i + '0';
		else
			symb_array[i] = 'A' - 10 + i;
		i++;
	}
	symb_array[i] = '\0';
}

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

char *ft_itoa_base(int number, int base)
{
	char *tab;
	char *str;
	int	size;
	int neg;

	if (base > MAX_BASE || base < 2)
		return (NULL);
	if (!(tab = (char*)malloc(sizeof(char) * base + 1)))
		return (NULL);
	prepare_symbols_array(tab, base);
	size = predict_size(number, base);
	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	neg =  (base == 10 && number < 0) ? 1 : 0;
	while (--size > -1)
	{
		str[size] = (number < 0) ? tab[-(number % base)] : tab[number % base];
		number = number / base;
	}
	neg ? str[0] = '-' : 0;
	free(tab);
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
