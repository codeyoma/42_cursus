#include <stdio.h>

#include "libft.h"

int main(int argc, char **argv) {

	argv = NULL;
	if (argc == 1)
	{
		const char *str = ",a,b,c,de,";
		printf("%s\n", str);
		char **arr = ft_split(str, ',');

		for (size_t i = 0; arr[i]; i++) {
			printf("%s\n", arr[i]);
		}
	}
	else
	{
		printf("\n-----------------\n");
		const char *str2 = ",,,a,,b,,,,c,,,,d,,";
		char **arr2 = ft_split(str2, ',');
		for (size_t i = 0; arr2[i]; i++) {
			printf("%s\n", arr2[i]);
		}
	}
	return 0;
}
