/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{

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
