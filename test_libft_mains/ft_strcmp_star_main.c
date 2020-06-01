#include "libft.h"
#include <stdio.h>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int i;

	if (argc != 3)
	{
		perror("need exactly two args:\n\t\targv[1] the string to compare\n" \
				"\t\targv[2] the string that contains stars.");
		return (0);
	}
	i = ft_str_star_cmp(argv[1], argv[2]);
	printf("for the inputs: [%s] and [%s]\nthe result is: ", argv[1], argv[2]);
	if (i)
		printf("\033[32mMATCH!\033[0m\n");
	else
		printf("\033[31mno MATCH!\033[0m\n");
	return (0);
}
