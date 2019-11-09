/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:26:50 by charmstr          #+#    #+#             */
/*   Updated: 2019/11/10 00:50:33 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: use of malloc, and free
**
** RETURN: the array of strings separated by c, or NULL if malloc failed or if
** empty string
*/

static int	find_start(char const *s, char c, int next_start)
{
	while (s[next_start] == c)
		next_start++;
	return (next_start);
}

static int	find_end(char const *s, char c, int next_end)
{
	while (s[next_end] == c)
		next_end++;
	while (s[next_end] && s[next_end] != c)
		next_end++;
	return (next_end);
}

static int	size_array(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*free_nested(char **ptr, int k)
{
	while (--k >= 0)
	{
		free(ptr[k]);
		ptr[k] = NULL;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char **ptr_array;
	int i;
	int k;

	i = 0;
	k = 0;
	if (!s || !(ptr_array = (char **)malloc(sizeof(char*) * size_array(s, c) \
					+ 1)))
		return (NULL);
	ptr_array[size_array(s, c)] = NULL;
	while (ptr_array[k])
	{
		ptr_array[k] = ft_substr(s, find_start(s, c, i), find_end(s, c, i) \
				- find_start(s, c, i));
		if(!(ptr_array[k]))
			return (free_nested(ptr_array, k));
		i = find_end(s, c, i) + 1;
		k++;
	}
	return (ptr_array);
}
