/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:51:43 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 17:51:48 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_msg(char *reason, char *command, char *message)
{
	ft_putstr_fd(reason, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(message, 2);
}

char	*search_expansion_value(t_mini *mini, char *str_in)
{
	t_env	*content;
	t_list	*list;
	char	*value;

	value = NULL;
	list = mini->list;
	while (list)
	{
		content = list->content;
		if (ft_strcmp(content->name, str_in))
		{
			value = ft_strdup(content->value);
			return (value);
		}
		list = list->next;
	}
	return (NULL);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_clean_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
}
