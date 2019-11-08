/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:15:50 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 16:47:54 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			*((unsigned char *)s + i) = 0;
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	char tab[] = "123cava?";
	char tab2[] = "123cava?";

	printf("sizeof tab: %lu\n",sizeof(tab));
	printf("tab is \"%s\"\n",tab);
	ft_bzero(tab, sizeof(tab));
	printf("sizeof tab: %lu\n",sizeof(tab));
	printf("tab is \"%s\"\n",tab);

	printf("sizeof tab2: %lu\n",sizeof(tab2));
	printf("tab2 is \"%s\"\n",tab2);
	bzero(tab2, sizeof(tab2));
	printf("sizeof tab2: %lu\n",sizeof(tab2));
	printf("tab2 is \"%s\"\n",tab2);

	return (0);
}
