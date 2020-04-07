/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:26:50 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/13 23:05:05 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** note:	this function will append a char to a string that does not need to
**			be existing. the string is updated and memory of the old string is
**			freed anyway.
**
** RETURN:	1 if OK
**			0 elsewise.
*/

int	ft_strappend(char **str, char c)
{
	char *char_str;
	char *old;

	old = *str;
	if (!(char_str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	char_str[0] = c;
	char_str[1] = '\0';
	if (!*str)
	{
		*str = char_str;
		return (1);
	}
	else
	{
		*str = ft_strjoin(old, char_str);
		free(old);
		free(char_str);
		if (!(*str))
			return (0);
		return (1);
	}
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *str;
	if (argc != 2)
	{
		printf("need one string as arg\n");
		return (0);
	}
	if (!(str = ft_strdup(argv[1])))
	{
		perror("malloc");
		return (0);
	}
	printf("the char to be added: [%c]\nthe initial string: [%s]\n", 'C', str);
	if (!ft_strappend(&str, 'C'))
	{
		perror("failure in ft_strappend");
		return (0);
	}
	printf("the appended string is: [%s]\n", str);
	char *str2 = NULL;
	printf("now try with an initial NULL arg\n");
	printf("the result is: [%d], the new string is: [%s]\n", ft_strappend(&str2, 'C'), str2);
	return (0);
}
