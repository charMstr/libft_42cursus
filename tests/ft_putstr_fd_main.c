/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:19:17 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 16:41:02 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
/*
** note: usefull for error messages: 1 --> stdout		2 --> stderr
**
** note2: if fd was not valid, message is redirected to stderr
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		write(2, s, ft_strlen(s));
}

int	main()
{
	char *str = "hey salut comment ca va?";
	int fd;

	//if ((fd = open("errors", O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	if ((fd = open("errors", O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	{
		printf("failed to open/creat file\n");
		return (0);
	}
	printf("%d\n", fd);
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(str, -42);
	ft_putstr_fd(str, fd);
	return (0);
}
//test with command: ./a.out 2>errors.txt
