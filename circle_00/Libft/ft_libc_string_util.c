/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	temp = ft_calloc(len, sizeof(char));
	if (temp)
		ft_memcpy(temp, s1, len);
	return (temp);
}
