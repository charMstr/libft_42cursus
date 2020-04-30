#include <stdio.h>
#include "libft.h"

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_list	*head;
	char	**array;
	char	**modified;

	head = NULL;
	array = NULL;
	printf("len null array: [%d]\n", ft_array_len(array));

	ft_array_free(array, ft_array_len(array));
	array = ft_array_add(array, "hey1");
	array = ft_array_add(array, "hey2");
	array = ft_array_add(array, "hey3");
	array = ft_array_add(array, "hey4");
	//printf("array = [%p]\n", array);
	ft_array_debug(array);
	ft_array_free(array, ft_array_len(array));
	//leaks ok
	while (1)
		;
	return (0);
}
