/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:14:36 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 16:45:25 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** the function still copies the character c if encountered
** note: if pointers are NULL: segfault results in origina function
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if ((unsigned char)c == *((unsigned char *)src + i))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char *string1 = "hello world!";
	char *dest2;
	char *dest1;
	char *ret1;
	char *ret2;

	if (!(dest2 = (char *)malloc(sizeof(char) * 13)))
		return (0);
	if (!(dest1 = (char *)malloc(sizeof(char) * 13)))
		return (0);
	int i;
	i = 0;
	while (i < 12)
	{
		*(dest1 + i) = '-';
		*(dest2 + i) = '-';
		i++;
	}
	ret1 = ft_memccpy(dest1, string1, 'w', 13);
	ret2 = memccpy(dest2, string1, 'w', 13);
	printf("dest1 is: \"%s\"\n",dest1);
	printf("dest2 is: \"%s\"\n",dest2);

	*ret1 = '9';
	*ret2 = '9';
	ft_putchar(*ret1);
	ft_putchar('\n');
	ft_putchar(*ret2);
	ft_putchar('\n');
	printf("dest1 is: \"%s\"\n",dest1);
	printf("dest2 is: \"%s\"\n",dest2);
	return (0);
}
