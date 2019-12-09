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

/*
** note:	this function will predict the size of a number, given its base.
**
** note2:	if the base is 10, then if the numebr is negative the predicted
**			the redicted size is +1.
**
** RETURN:	the predicted size of a given number, according to the base.
*/

int	ft_size_num_base(int num, int base)
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

