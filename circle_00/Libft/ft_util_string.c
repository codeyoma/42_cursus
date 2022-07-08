/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

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
}
