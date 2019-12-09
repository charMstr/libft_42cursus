/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:07:52 by charmstr          #+#    #+#             */
/*   Updated: 2019/12/09 03:14:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	size = ft_size_num_base(n, 10);
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
