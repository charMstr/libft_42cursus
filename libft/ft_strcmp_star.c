/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:33:16 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/14 00:10:30 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note:	this function will try to match one input string str, with a second
**			string star that will contain eventually one or more kleen star
**			operators.
** note:	no escaped sequences are taken into account.
**
** input:	str: could contain a star, but it would be a star that is just a
**			normal character.
** RETURN:	1 match
**			0 no match or NULL inputs.
*/

/*
** note:	check if the string contains only the '*' char
** RETURN:	1 yes
**			0 no
*/
static int	stars_only(char *str)
{
	int i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_str_star(char *str, char *star, int i, int j)
{
	while (str[i] && star[j] && (str[i] == star[j]))
	{
		if (star[j] == '*')
			break;
		i++;
		j++;
	}
	if (stars_only(star + j) || (!str[i] && !star[j]))
		return (1);
	if (!str[i] || !star[j] || star[j] != '*')
		return (0);
	while (star[j + 1] == '*')
		j++;
	while (str[i] && str[i] != star[j + 1])
		i++;
	if (!str[i])
		return (0);
	return (ft_str_star(str + i, star + j + 1, 0 , 0) \
			|| ft_str_star(str + i + 1, star + j, 0 , 0));
}

int			ft_strcmp_star(char *str, char *star)
{
	if (!str || !star)
		return (0);
	return (ft_str_star(str, star, 0, 0));
}
