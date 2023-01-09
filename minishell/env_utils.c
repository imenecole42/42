/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:48:28 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 17:48:38 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*load_env_name(char *src)
{
	char	*name;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0' && src[len] != '=')
		len++;
	name = malloc((len + 1) * sizeof(char));
	if (!name)
		return (NULL);
	while (i < len)
	{
		name[i] = src[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

static char	*concat_env_strs(char *str1, char *str2)
{
	char	*rslt;
	char	*tmp;

	tmp = ft_strjoin(str1, "=");
	rslt = ft_strjoin(tmp, str2);
	if (tmp)
		free(tmp);
	if (rslt)
		return (rslt);
	return (NULL);
}

char	**envlist_to_strings(t_mini *mini)
{
	char	**env_mini;
	int		count;
	t_env	*content;
	t_list	*list;

	list = mini->list;
	count = ft_lstsize(list);
	env_mini = (char **)malloc((count + 1) * sizeof(char *));
	if (!env_mini)
		return (NULL);
	count = 0;
	list = mini->list;
	while (list != NULL)
	{
		content = list->content;
		env_mini[count++] = concat_env_strs(content->name, content->value);
		list = list->next;
	}
	env_mini[count] = NULL;
	return (env_mini);
}

char	*load_env_value(char *str)
{
	unsigned int	i;
	char			*value;
	int				j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	value = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!value)
		return (NULL);
	i++;
	while (i < ft_strlen(str))
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

int	init_env(t_mini *mini, char **env)
{
	int		i;
	t_list	*list;
	t_env	*content;

	i = 0;
	list = NULL;
	while (env[i])
	{
		content = malloc(sizeof(*content));
		list = ft_lstnew(content);
		ft_lstadd_back(&(mini->list), list);
		content = list->content;
		content->name = load_env_name(env[i]);
		content->value = load_env_value(env[i]);
		if (content->name == NULL || content->value == NULL)
			return (-1);
		i++;
	}
	return (0);
}
