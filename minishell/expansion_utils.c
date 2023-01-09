/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:33:07 by omechri           #+#    #+#             */
/*   Updated: 2022/10/26 11:33:10 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	local_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*local_strjoin(char *s1, char const *s2)
{
	char	*rslt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rslt = malloc((local_strlen(s1) + local_strlen(s2) + 1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		rslt[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		rslt[i] = s2[j];
		i++;
		j++;
	}
	rslt[i] = '\0';
	return (rslt);
}

char	*concat_strs(char *result, char *before_str, char *expanded_str)
{
	char	*tmp;

	tmp = local_strjoin(before_str, expanded_str);
	free(before_str);
	free(expanded_str);
	expanded_str = local_strjoin(result, tmp);
	free(tmp);
	if (result)
		free(result);
	result = expanded_str;
	return (result);
}

char	*find_and_expand_var_name(t_mini *mini, char *str, int *i, int *j)
{
	int		k;
	char	*tmp;
	char	*expanded_str;
	char	*before_str;

	k = *i + 1;
	tmp = get_variable_name(&str[k], &k);
	if (tmp)
	{
		expanded_str = expand_variable_name(mini, tmp);
		before_str = ft_substr(str, *j, (*i - *j));
		free(tmp);
	}
	else
	{
		expanded_str = NULL;
		before_str = ft_substr(str, *j, *i - *j + 1);
	}
	tmp = local_strjoin(before_str, expanded_str);
	free(before_str);
	free(expanded_str);
	*j = k;
	*i = k;
	return (tmp);
}

char	*expand(t_mini *mini, char *str)
{
	int		i;
	int		j;
	char	*before_str;
	char	*result;
	char	*tmp;

	i = 0;
	j = 0;
	result = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = find_and_expand_var_name(mini, str, &i, &j);
			before_str = result;
			result = local_strjoin(before_str, tmp);
			if (before_str)
				free(before_str);
			free(tmp);
		}
		else
			i++;
	}
	before_str = ft_substr(str, j, i - j);
	return (concat_strs(result, before_str, NULL));
}
