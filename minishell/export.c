/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:24:03 by omechri           #+#    #+#             */
/*   Updated: 2022/10/03 16:24:07 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_var_env(t_mini *mini, char *name, char *value)
{
	t_list	*list;
	t_env	*content;

	content = malloc(sizeof(*content));
	if (!content)
		return ;
	list = ft_lstnew(content);
	ft_lstadd_back(&(mini->list), list);
	content->name = name;
	content->value = value;
}

int	update_var_env(t_mini *mini, char *name, char *value)
{
	t_env	*content;
	t_list	*list;

	list = mini->list;
	while (list)
	{
		content = list->content;
		if (ft_strcmp(content->name, name))
		{
			free(content->value);
			content->value = value;
			return (1);
		}
		list = list->next;
	}
	return (0);
}

void	export_print(t_mini *mini)
{
	t_env	*content;
	t_list	*list;

	list = mini->list;
	while (list != NULL)
	{
		content = list->content;
		ft_putstr_fd("export ", 1);
		ft_putstr_fd(content->name, 1);
		if (content->value[0] != '\0')
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(content->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}

int	export_variables(t_mini *mini, char **cmd, int length)
{
	int		i;
	char	*name;
	char	*value;
	int		status;

	status = 0;
	i = 1;
	while (i < length)
	{
		name = load_env_name(cmd[i]);
		value = load_env_value(cmd[i]);
		if (update_var_env(mini, name, value) == 1)
			free(name);
		else if (is_valid(name))
			add_var_env(mini, name, value);
		else
		{
			err_msg(cmd[i], "export", "invalid identifier\n");
			free(name);
			free(value);
			status = 1;
		}
		i++;
	}
	return (status);
}

int	fct_export(t_mini *mini, char **cmd, int length)
{
	int	status;

	status = 0;
	if (length == 1)
		export_print(mini);
	else if (length > 1)
		status = export_variables(mini, cmd, length);
	return (status);
}
