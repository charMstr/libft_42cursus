/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:32:59 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 17:43:03 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) \
			|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int i;

	i = -100;
	while (i < 1000)
	{
		if (isalnum(i) != ft_isalnum(i))
		{
			printf("failed to imitate the behavior of the orignal isalnum fn\n");
		}
		else
			printf("ok\n");
		i++;
	}
	return (0);
}
