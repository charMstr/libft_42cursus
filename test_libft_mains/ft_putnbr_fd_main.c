/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:27:03 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 17:12:00 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
			ft_putnbr_fd(-(n / 10), fd);
	}
	else if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	(n > 0) ? ft_putchar_fd(n % 10 + '0', fd) \
		: ft_putchar_fd(-(n % 10) + '0', fd);
}

int	main()
{
	int i;
	int i2;
	int fd;


	if ((fd = open("errors.txt", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
	{
		printf("failed to open fildes\n");
		return (0);
	}
	printf("%d\n",fd);

	i = 123;
	i2 = -123;
	ft_putnbr_fd(i, 1);
	printf("\n");
	ft_putnbr_fd(i2, 1);
	printf("\n");
	ft_putnbr_fd(i, -1);
	printf("\n");
	ft_putnbr_fd(i2, -1);
	printf("\n");
	ft_putnbr_fd(i, 3);
	printf("\n");
	ft_putnbr_fd(i2, 3);
	printf("\n");
	return (0);
}
