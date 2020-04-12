#include "libft.h"

/*
** input:	- arg1: head of list (ex: &head). or any link within the list but
**				the arg will then become the head.
**			- arg2: new link to be added
**
** note2:	if *alst is NULL, it means the list was empty. new list is created
*/

void	ft_dlstadd_front(t_dlist **alst, t_dlist *new)
{
	t_dlist *tmp;

	if (!alst || !new)
		return ;
	tmp = *alst;
	if (!tmp)
	{
		*alst = new;
		return ;
	}
	while (tmp->previous)
		tmp = tmp->previous;
	new->next = tmp;
	tmp->previous = new;
	*alst = new;
}
