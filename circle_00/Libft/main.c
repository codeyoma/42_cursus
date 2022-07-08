#include <stdio.h>

#include "libft.h"

int main(void) {
	const char *str = "a,b,c,d";
	char **arr = ft_split(str, ',');

	for (size_t i = 0; arr[i]; i++) {
		printf("%s\n", arr[i]);
	}
}
