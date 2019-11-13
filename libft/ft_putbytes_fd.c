/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:49:23 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 18:30:35 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: on the given fd, will print bytes after bytes of the void pointer.
**
** big endian
*/

void	ft_putbytes_fd(void *thing, int sizeof_thing, int fd)
{
	char *ptr;

	ptr = (char*)thing;
	if (!thing || !sizeof_thing)
		return ;
	if (sizeof_thing > 1)
		ft_putbytes_fd(ptr + 1, --sizeof_thing, fd);
	ft_putbits_fd(*ptr, fd);
}
