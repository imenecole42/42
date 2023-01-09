/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:12 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 18:03:19 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_list **lst, t_list *new_element)
{
	ft_lstadd_back(&new_element, *lst);
	*lst = new_element;
}

void	ft_lstadd_back(t_list **lst, t_list *new_element)
{
	if (*lst != NULL)
		ft_lstlast(*lst)->next = new_element;
	else
		*lst = new_element;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (lst->content)
		{
			if (del)
				(*del)(lst->content);
			else
				free(lst->content);
		}
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*current;

	if (!lst || !(*lst))
		return ;
	next = *lst;
	current = *lst;
	while (next)
	{
		next = next->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
