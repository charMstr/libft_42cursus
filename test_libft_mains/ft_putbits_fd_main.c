/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits_fd_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:35:48 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 17:47:11 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** this function will display each bits in a char in this format "[0100 0001]"
*/

void	ft_putbits_fd(char c, int fd)
{
	char i;

	i = 8;
	ft_putchar_fd('[', fd);
	while (--i >= 0)
	{
		ft_putchar_fd(((c & (1 << i)) >> i) + 48, fd);
		if (i == 4)
			ft_putchar_fd(' ', fd);
	}
	ft_putchar_fd(']', fd);
}

/*
** this function will print the bits of a string
*/

void ft_putstrbits(char *str,int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putbits_fd(str[i], fd);
		write(1, " ", 1);
		i++;
	}
	printf("=> END OF STRING <=");
}

int	main()
{

	char str[] = "hAllo\n";
	ft_putbits_fd('A', -1);
	write(1, "\n", 1);
	ft_putstrbits(str, 1);
	return (0);
}
