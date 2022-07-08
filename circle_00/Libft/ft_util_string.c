/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	src_len;
	size_t	dst_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len)
		start = src_len;
	dst_len = ft_strlen(s + start);
	if (dst_len > len)
		dst_len = len;
	temp = ft_calloc(dst_len + 1, sizeof(char));
	if (temp)
		ft_memcpy(temp, s + start, dst_len);
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	t_len = ft_strlen(s1) + ft_strlen(s2);
	temp = ft_calloc(t_len + 1, sizeof(char));
	if (temp)
	{
		ft_strlcat(temp, s1, t_len + 1);
		ft_strlcat(temp, s2, t_len + 1);
	}
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_pos;
	size_t	rear_pos;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front_pos = 0;
	rear_pos = ft_strlen(s1);
	if (0 < rear_pos)
	{
		while (ft_strchr(set, s1[front_pos]))
			front_pos++;
		while (ft_strchr(set, s1[rear_pos - 1]))
			rear_pos--;
	}
	return (ft_substr(s1, front_pos, rear_pos - front_pos + 1));
}

/*
// static char	**_realloc_and_free(char **org, size_t cnt, int key)
// {
// 	char	**temp;
// 	if (!key)
// 	{
// 		while (temp[key])
// 		{
// 			free(temp[key]);
// 			key++;
// 		}
// 		free(temp);
// 		return (NULL);
// 	}

// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**temp;

// 	if (!s)
// 		return (NULL);
// 	temp = NULL;
// }
*/


char	**__ft_split(char const *s, char c, int index)
{
	char	**result;
	char	*s_end;

	if (*s == '\0')
		return (ft_calloc(index * 1, sizeof(*result)));
	s_end = (char *)s;
	while (*s_end && *s_end != c)
		++s_end;
	result = __ft_split(s_end + (*s_end != '\0'), c, index + 1);
	if (result)
	{
		result[index] = ft_substr(s, 0, s_end - s);
		if (result[index] == NULL)
		{
			while (result[++index])
				free(result[index]);
			free(result);
			return (NULL);
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	return (__ft_split(s, c, 0));
}
