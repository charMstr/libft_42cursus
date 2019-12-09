/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:47:47 by charmstr          #+#    #+#             */
/*   Updated: 2019/12/09 01:53:59 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
** note:	this funciton will look for a char in a string and give the incdex
**			of the very first occurence.
**
**			uefull for checking the presence of a flag in a predefined string.
**
** RETURN:	the index of the first character 'c' found in string 'str'
**			-1 if failure
*/

int ft_strichr(char *str, char c)
{
	int index;

	index = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	char *str = "salut tout le monde";
	int i;

	i = ft_strichr(str, argv[1][0]);
	printf("%d\n", i);
	return (0);
}
