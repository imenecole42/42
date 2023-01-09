/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:06:47 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 17:06:57 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_content(t_env *content)
{
	if (content)
	{
		free(content->name);
		free(content->value);
		free(content);
	}
}

void	delete_var_env(t_mini *mini, char *name)
{
	t_env	*content;
	t_list	*previous;
	t_list	*current;

	previous = NULL;
	current = mini->list;
	while (current)
	{
		content = current->content;
		if (ft_strcmp(content->name, name))
		{
			if (previous)
				previous->next = current->next;
			else
			{
				previous = current->next;
				mini->list = previous;
			}
			free_content(content);
			free(current);
			break ;
		}
		previous = current;
		current = current->next;
	}
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '_' && ft_isalpha(str[0]) == 0)
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != '_' && ft_isalpha(str[i]) == 0 && ft_isdigit(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	fct_unset(t_mini *mini, char **cmd, int length)
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (is_valid(cmd[i]))
			delete_var_env(mini, cmd[i]);
		else
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
