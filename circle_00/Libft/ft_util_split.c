/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

static void	_free_str_vector(char **str_vector)
{
	size_t	i;

	i = 0;
	if (str_vector)
	{
		while (str_vector[i])
		{
			free(str_vector[i]);
			i++;
		}
	}
	free(str_vector);
	str_vector = NULL;
}

static char	**_realloc(char **org, char *append, size_t *size, size_t *cur)
{
	char	**temp;
	size_t	i;

	if (*cur < *size - 1)
	{
		org[(*cur)++] = append;
		return (org);
	}
	*size *= 2;
	temp = ft_calloc(*size, sizeof(char *));
	if (temp)
	{
		temp[(*cur)++] = append;
		i = 0;
		while (i < *cur - 1)
		{
			temp[i] = org[i];
			i++;
		}
		_free_str_vector(org);
		return (temp);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	char	*pos;
	size_t	size;
	size_t	cur;

	if (!s)
		return (NULL);
	size = 2;
	cur = 0;
	temp = ft_calloc(size, sizeof(char *));
	while (temp && *s)
	{
		if (*s != c)
		{
			pos = ft_strchr(s, c);
			if (!pos)
				pos = (char *)s + ft_strlen(s);
			temp = _realloc(temp, ft_substr(s, 0, pos - s), &size, &cur);
			s = pos;
		}
		s++;
	}
	return (temp);
}
