/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_num_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 03:09:28 by charmstr          #+#    #+#             */
/*   Updated: 2019/12/09 03:13:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
/*
** note:	this function will predict the size of a number, given its base.
**
** note2:	if the base is 10, and the numebr is negative and the option
**			absolute is zero, then we add extra space for the minus sign.
**
** RETURN:	the predicted size of a given number, according to the base.
*/

int	ft_size_num_base(long num, int base, int absolute)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	if (base == 10 && num < 0 && !absolute)
		i++;
	while (num)
	{
		num = num / base;
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int i;
	i = ft_size_num_base(atol(argv[1]), 10, atoi(argv[2]));
	printf("%d\n", i);
	return (0);
}
