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
	return 0;
}
