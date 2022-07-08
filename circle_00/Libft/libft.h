/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#ifndef LIBFT_H

# include <stddef.h>

/*		ft_libc_ctype_syntax.c 
**==============================================================================
*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/*		ft_libc_ctype_convert.c 
**==============================================================================
*/
int		ft_toupper(int c);
int		ft_tolower(int c);

/*		ft_libc_string_util.c
**==============================================================================
*/
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);

/*		ft_libc_string_cpy.c
**==============================================================================
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*		ft_libc_string_locate_and_compare.c
**==============================================================================
*/
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*		ft_libc_stdlib.c
**==============================================================================
*/
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

/*		ft_util_io.c
**==============================================================================
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
