#include "libft.h"
#include <stdio.h>

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *str;
	int res;

	if (argc != 3)
	{
		printf("Error\nUsage: enter 2 strings as an arguments\n");
		return (0);
	}
	printf("try to find any character from %s, in %s\n", argv[2], argv[1]);
	res = ft_stristr(argv[1], argv[2]);
	printf("index of the first char found: %d\n", res);
	return (0);
}
