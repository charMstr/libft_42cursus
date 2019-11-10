/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:56:17 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 15:16:28 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note: if fd is not valid, then the message is redirected on stderr (fd = 2)
**
** adds a '\n' after a putstr
*/

void	ft_putendl_fd(char *s, int fd)
{
	char c;

	c = '\n';
	if (!s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
	{
		write(2, s, ft_strlen(s));
		write(2, &c, 1);
	}
	else
		write(fd, &c, 1);
}

int	main()
{
	char *string = "hello world!";
	//ft_putendl_fd(string, 0);
	ft_putendl_fd(string, 1);
	//ft_putendl_fd(string, 2);
	ft_putendl_fd(string, 6);
	return (0);
}
