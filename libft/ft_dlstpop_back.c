#include "libft.h"

/*
** note:	this function will delete the last link of the double linked list.
**			see ft_dlstpop_front as well.
*/

void	ft_dlstpop_back(t_dlist **head, void (*del)(void*))
{
	t_dlist **current;
	t_dlist *then;

	if (!head || !del || !*head)
		return ;
	current = head;
	while (*current)
	{

		then = (*current)->next;
		if (!then)
		{
			free(*current);
			*current = NULL;
			return ;
		}
		current = &(*current)->next;
	}
}
