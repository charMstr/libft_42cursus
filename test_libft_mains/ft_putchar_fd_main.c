/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:55:47 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 16:44:14 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

/*
** note: 1:stdin  2:stderr		do we need to protect fd??
**
** note2: if fd is not valid, then the write goes to stderr (fd = 2)
*/

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		write(2, &c, 1);
}

int	main()
{
	char *str = "hey salut";
	int fd;

	if ((fd = open("errors", O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
	{
		printf("failed to open fildes\n");
		return (0);
	}
	ft_putchar_fd(str[0], 1);
	ft_putchar_fd(str[0], -42);
	ft_putchar_fd(str[0], fd);
	return (0);
}
