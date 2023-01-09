/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:33:07 by omechri           #+#    #+#             */
/*   Updated: 2022/10/26 11:33:10 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig	g_sig;

char	*get_variable_name(const char *str, int *counter)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	if (str[i] && str[i] == '?')
	{
		value = ft_strdup("?");
		i++;
	}
	else if (str[i] && (str[i] == '_' || ft_isalpha(str[i]) == 1))
	{
		i++;
		while (str[i])
		{
			if (str[i] == '_' || ft_isalpha(str[i]) == 1
				|| ft_isdigit(str[i]) == 1)
				i++;
			else
				break ;
		}
		value = ft_substr(str, 0, i);
	}
	*counter += i;
	return (value);
}

char	*expand_variable_name(t_mini *mini, char *var_name)
{
	char	*result;

	result = NULL;
	if (var_name[0] == '?')
		result = ft_itoa(g_sig.status);
	else
		result = search_expansion_value(mini, var_name);
	return (result);
}

char	*expand_quoted_str(t_mini *mini, char *str, int *read_chars)
{
	int		j;
	char	*tmp;
	char	*expanded;
	char	quote;

	j = 1;
	quote = str[0];
	while (str[j] != quote)
		j++;
	tmp = ft_substr(str, 1, j - 1);
	expanded = tmp;
	if (quote == '\"')
	{
		expanded = expand(mini, tmp);
		free(tmp);
	}
	j += 1;
	*read_chars = j;
	return (expanded);
}

char	*expand_rest(t_mini *mini, char *str, char *rslt, int i)
{
	char	*before_str;

	before_str = ft_substr(str, 0, i);
	rslt = concat_strs(rslt, expand(mini, before_str), NULL);
	free(before_str);
	return (rslt);
}

char	*pre_expand(t_mini *mini, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*rslt;
	char	*before_str;

	i = 0;
	j = 0;
	k = 0;
	rslt = NULL;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			before_str = ft_substr(str, k, (i - k));
			rslt = concat_strs(rslt, expand(mini, before_str),
					expand_quoted_str(mini, &str[i], &j));
			free(before_str);
			i += j;
			k = i;
		}
		else
			i++;
	}
	return (expand_rest(mini, str + k, rslt, i));
}
