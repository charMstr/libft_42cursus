/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:22:12 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/08 19:32:34 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int position;

	position = -1;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			position = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	else if (position >= 0)
		return ((char *)(s + position));
	else
		return (NULL);
}

int	main(int argc, char *argv[])
{
	char *string = "hey salut tout le monde!";
	int i;

	i = 0;
	while (string[i])
	{
		if (strrchr(string, string[i]) != ft_strrchr(string,string[i]))
		{
			printf("failed to immitate the behavior of strrchr function\n");
		}
		i++;
	}
	return (0);
}
