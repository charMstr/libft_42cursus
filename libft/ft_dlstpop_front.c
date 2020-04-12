#include "libft.h"

/*
** note:	this function will delete the front link of the double linked list.
**			see ft_dlstpop_back as well.
*/

void	ft_dlstpop_front(t_dlist **head, void (*del)(void*))
{
	t_dlist **current;
	t_dlist *then;

	if (!head || !del || !*head)
		return ;
	current = head;
	while (*current)
	{

		then = (*current)->previous;
		if (!then)
		{
			free(*current);
			*current = NULL;
			return ;
		}
		current = &(*current)->previous;
	}
}

