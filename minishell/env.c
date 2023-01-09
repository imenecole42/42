/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:02:43 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 18:02:47 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fct_env(t_mini *mini, int nb_arg)
{
	t_env	*content;
	t_list	*list;

	list = mini->list;
	if (nb_arg > 1)
	{
		ft_putendl_fd("unsupported ", 2);
		return (1);
	}
	while (list != NULL)
	{
		content = list->content;
		if (content->value[0] != '\0')
		{
			ft_putstr_fd(content->name, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(content->value, 1);
		}
		list = list->next;
	}
	return (0);
}
