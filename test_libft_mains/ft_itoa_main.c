/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:07:52 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 00:21:19 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	predict_size(int n)
{
	int size;

	size = 0;
	if (n < 0)
		size++;
	while (n < -9 || n > 9)
	{
		size++;
		n = n / 10;
	}
	return (++size);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	size = predict_size(n);
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (size + 1))))
		return (NULL);
	ptr[size] = '\0';
	while ((n > 9) || (n < -9))
	{
		ptr[--size] = (n < 0) ? -(n % 10) + '0' : n % 10 + '0';
		n = n / 10;
	}
	ptr[--size] = (n < 0) ? -(n % 10) + '0' : n % 10 + '0';
	ptr[0] = (size == 1) ? '-' : ptr[0];
	return (ptr);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("please enter a single string: digits\n");
		return (0);
	}
	printf("original number: %d\n", atoi(argv[1]));
	printf("size of string: %d\n", predict_size(atoi(argv[1])));
	printf("result of my func:%s\n",ft_itoa(atoi(argv[1])));

	return (0);
}
