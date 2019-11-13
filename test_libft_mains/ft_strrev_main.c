/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:31:08 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 16:22:06 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;

	if (!str)
		return (NULL);
	j = 0;
	i = ft_strlen(str) - 1;
	while (i > j)
	{
		str[j] ^= str[i];
		str[i] ^= str[j];
		str[j] ^= str[i];
		j++;
		i--;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("need 1 arg\n");
		return (0);
	}
	printf("%s\n",ft_strrev(argv[1]));
	return (0);
}
