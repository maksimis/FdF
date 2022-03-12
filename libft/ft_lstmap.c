/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:24:45 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/21 12:16:51 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew_tmp(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

void	ft_lstclear_tmp(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			(*lst) = tmp;
		}
	}
}

void	ft_lstadd_back_tmp(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = *lst;
		while (last->next)
			last = (last)->next;
		last->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	result = ft_lstnew_tmp(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew_tmp(f(lst->content));
		if (!new)
		{
			ft_lstclear_tmp(&result, del);
			return (NULL);
		}
		ft_lstadd_back_tmp(&result, new);
		lst = lst->next;
	}
	return (result);
}
