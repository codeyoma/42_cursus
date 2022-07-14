/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*temp;
	size_t	len;

	len = !n;
	while (n)
	{
		len++;
		n /= 10;
	}
	len = (n < 0) + len;
	temp = ft_calloc(len + 1, sizeof(char));
	if (temp)
	{
		if (n < 0)
			temp[0] = '-';
		if (!n)
			temp[--len] = '0';
		while (n)
		{
			temp[--len] = '0' + ((1 - ((n < 0) << 1)) * (n % 10));
			n /= 10;
		}
	}
	return (temp);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;

	if (!s || !f)
		return (NULL);
	temp = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (temp)
	{
		i = 0;
		while (s[i])
		{
			temp[i] = f(i, s[i]);
			i++;
		}
	}
	return (temp);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
