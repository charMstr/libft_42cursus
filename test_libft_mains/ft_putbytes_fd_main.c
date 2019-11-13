/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:49:43 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 18:30:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
** note: on the given fd, will print bytes after bytes of the void pointer.
** big endian
*/

void ft_putbytes_fd(void *thing, int sizeof_thing, int fd)
{
	char *ptr;

	ptr = (char*)thing;
	if (!thing || !sizeof_thing)
		return ;
	if (sizeof_thing > 1)
		ft_putbytes_fd(ptr + 1, --sizeof_thing, fd);
	ft_putbits_fd(*ptr, fd);
}

int	main(int argc, char *argv[])
{
	int i;
	short s;
	unsigned long long t;

	t = 4777777777888;
	s = 1 << 10;
	i = 1 << 15;
	ft_putbytes_fd(NULL, sizeof(t), 1);
	printf("\n");
	ft_putbytes_fd(&s, 0, 1);
	printf("\n");
	ft_putbytes_fd(&i, sizeof(i), 1);
	printf("\n");
	i = 1 << 16;
	ft_putbytes_fd(&i, sizeof(i), 1);
	printf("\n");
	if (argc == 2)
	{
		int i;

		i = ft_atoi(argv[1]);
		ft_putbytes_fd(&i, sizeof(i), 1);
		printf("\n");
		i = ~i + 1;
		ft_putbytes_fd(&i, sizeof(i), 1);
		printf("\n");
		ft_putstr_fd(ft_itoa(i), 1);
	}
	return (0);
}
