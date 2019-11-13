/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:55:09 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 17:34:12 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/*
** note: the pointer is not protected in the original function
*/

char	*ft_strchr(const char *s , int c)
{
	int i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}

int	main(int argc, char *argv[])
{
	char *str = "heya salut a tous!!";
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(str, str[i]) != strchr(str, str[i]))
			printf("failed to immitate the behavior of strchr function \n");
		i++;
	}
	if (ft_strchr(str, '\0') != strchr(str, '\0'))
		printf("failed to immitate the behavior of strchr function \n");
	if (ft_strchr(str, 'X') != strchr(str, 'X'))
		printf("failed to immitate the behavior of strchr function \n");
	return (0);
}
