/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->next = NULL;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*temp;
	void	*f_temp;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		f_temp = f(lst->content);
		temp = ft_lstnew(f_temp);
		if (!temp)
		{
			free(f_temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = temp;
		else
			tail->next = temp;
		tail = temp;
		lst = lst->next;
	}
	return (head);
}
