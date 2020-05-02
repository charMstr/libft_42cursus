#include <stdio.h>
#include "libft.h"


int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	int	num1;
	int	num2;
	char *str1;
	char *str2;
	int		*ptr1;
	int		*ptr2;
	int		a = 16;
	int		b = 3625;
	t_list	*fist;
	char *hey = "hey";
	char *hoooo = "hoooo";
	t_list *link1;
	t_list *link2;
	t_list	link1_static;
	t_list	link2_static;

	str1 = ft_strdup("hey");
	str2 = ft_strdup("salut");
	num1 = 10;
	num2 = 42;
	ptr1 = &num1;
	ptr2 = &num2;
	printf("size of %s: %zu\n",str1, sizeof(str1));
	printf("size of %s: %zu\n",str2, sizeof(str2));
	printf("\nbefore swap:\n%p -> %s\n", str1, str1);
	printf("%p -> %s\n", str2, str2);
	ft_swap(&str1, &str2, sizeof(char*));
	printf("after swap:\n%p -> %s\n", str1, str1);
	printf("%p -> %s\n\n", str2, str2);

	printf("\nbefore swap:\n%p -> %d\n", ptr1, *ptr1);
	printf("%p -> %d\n", ptr2, *ptr2);
	ft_swap(ptr1, ptr2, sizeof(int));
	printf("\nafter swap:\n%p -> %d\n", ptr1, *ptr1);
	printf("%p -> %d\n\n", ptr2, *ptr2);

	printf("\nbefore swap:\n%p -> %d\n", &a, a);
	printf("%p -> %d\n", &b, b);
	ft_swap(&a, &b, sizeof(int));
	printf("\nafter swap:\n%p -> %d\n", &a, a);
	printf("%p -> %d\n\n", &b, b);

	//do nor use on string litterals...
	printf("HERE\n");
	printf("%s, %s\n", hey, hoooo);
	ft_swap(&hey, &hoooo, sizeof(char *));
	printf("%s, %s\n\n", hey, hoooo);

	link1 = ft_lstnew(str1);
	link2 = ft_lstnew(str2);
	link1->next = link2;
	printf("link1: [%p], link1->content: [%s], next: [%p]\n", link1, link1->content, link1->next);
	printf("link2: [%p], link2->content: [%s], next: [%p]\n-\n", link2, link2->content, link2->next);
	ft_swap(&link1, &link2, sizeof(t_list*));
	printf("link1: [%p], link1->content: [%s], next: [%p]\n", link1, link1->content, link1->next);
	printf("link2: [%p], link2->content: [%s], next: [%p]\n-\n", link2, link2->content, link2->next);
	ft_swap(&link1->next, &link2->next, sizeof(t_list*));
	printf("link1: [%p], link1->content: [%s], next: [%p]\n", link1, link1->content, link1->next);
	printf("link2: [%p], link2->content: [%s], next: [%p]\n-\n", link2, link2->content, link2->next);

	printf("\n\nwith static memory:\n");
	link1_static.content = str1;
	link1_static.next = &link2_static;
	link2_static.content = str2;
	link2_static.next = NULL;
	printf("link1: [%p], link1.content: [%s], next: [%p]\n", &link1_static, link1_static.content, link1_static.next);
	printf("link2: [%p], link2.content: [%s], next: [%p]\n", &link2_static, link2_static.content, link2_static.next);

	ft_swap(&link1_static.content, &link2_static.content, sizeof(char *));
	printf("\nlink1: [%p], link1.content: [%s], next: [%p]\n", &link1_static, link1_static.content, link1_static.next);
	printf("link2: [%p], link2.content: [%s], next: [%p]\n", &link2_static, link2_static.content, link2_static.next);

	/*
	ft_swap(&link1_static.next, &link2_static.next, sizeof(t_list*));
	printf("\nlink1: [%p], link1.content: [%s], next: [%p]\n", &link1_static, link1_static.content, link1_static.next);
	printf("link2: [%p], link2.content: [%s], next: [%p]\n", &link2_static, link2_static.content, link2_static.next);
	*/
	return (0);
}
