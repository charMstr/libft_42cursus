/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:23:45 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 18:29:20 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -500;
	while (i < 500)
	{
		if (isascii(i) != ft_isascii(i))
			printf("failed to imitate hthe behavior of the isascii fctn\n");
		i++;
	}
	return (0);
}
