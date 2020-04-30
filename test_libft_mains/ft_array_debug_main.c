#include <stdio.h>
#include "libft.h"

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char	**array;

	array = NULL;
	array = ft_array_add(array, "hey1");
	array = ft_array_add(array, "hey2");
	array = ft_array_add(array, "hey3");
	array = ft_array_add(array, "hey4");
	ft_array_debug(array);
	ft_array_free(array, ft_array_len(array));
	//while (1)
	//	;
	return (0);
}

