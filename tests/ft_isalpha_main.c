/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:03:17 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 17:20:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <xlocale.h> //forthe use of atoi

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < 1000)
	{
		if (isalpha(i+1) !=  ft_isalpha(i))
			printf("failed to match original behavior of isalpha function\n");
		i++;
	}
	return (0);
}
