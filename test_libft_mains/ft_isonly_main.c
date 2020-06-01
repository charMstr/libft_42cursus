#include <stdio.h>
#include "libft.h"
#include <assert.h>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int res;

	if (argc != 3)
	{
		printf("need two args: \n\t\t1_ string\n\t\t2_ char\n");
		return (0);
	}
	res = ft_isonly(argv[1], argv[2][0]);
	printf("for string: [%s] and char [%c], isonly-> %d\n", argv[1], argv[2][0], res);
	return (0);
}
