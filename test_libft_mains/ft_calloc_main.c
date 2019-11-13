/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:32:37 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/09 16:45:31 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct 	s_fake
{
	int i;
	char c;
}				t_fake;

/*
** arguments: the number of elements (+/- '\0' if strings..), then sizeof(*...)
*/

void	*ft_calloc(size_t count , size_t size)
{
	void *ptr;
	size_t i;

	i = 0;
	if (!(ptr = (void *)malloc(count * size)))
			return (NULL);
	else
		while (i < size * count)
		{
			*((unsigned char *)ptr + i) = 0;
			i++;
		}
		return (ptr);
}

int	main(int argc, char *argv[])
{
	int *ptr1;
	int *ptr2;
	//int *ptr2;
	//t_fake *fake_element;
	//t_fake *fake_element_table;
	//t_fake fake_element_table2[3];

	//if (!(ptr1 = (char *)ft_calloc(sizeof(*ptr1), 1)))
	//	return (0);
	//if (!(ptr2 = (int*)ft_calloc(sizeof(*ptr2), 1)))
		//return (0);
	//if (!(fake_element = (t_fake*)ft_calloc(sizeof(*fake_element), 1)))
		//return (0);
	//if (!(fake_element_table = (t_fake*)ft_calloc(sizeof(*fake_element_table), 3)))
		//return (0);
	if (!(ptr1 = (int *)calloc(5, sizeof(*ptr1))))
		return (0);
	if (!(ptr2 = (int *)ft_calloc(5, sizeof(*ptr2))))
		return (0);
	ptr1[1] = 42;
	ptr1[3] = 42;
	ptr2[1] = 42;
	ptr2[3] = 42;
	printf("sizof *ptr1 = %lu\n",sizeof(*ptr1));
	int i = 0;
	while (i < 1000)
	{
		printf("%d, %d\n", ptr1[i], ptr2[i]);
		i++;
	}
	return (0);
}
