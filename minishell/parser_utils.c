/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_delimeters(char delimeters[4])
{
	delimeters[0] = '|';
	delimeters[1] = '<';
	delimeters[2] = '>';
	delimeters[3] = '\0';
}

t_boolean	is_delimiter(char c)
{
	unsigned int	i;
	char			delimiters[4];

	fill_delimeters(delimiters);
	i = 0;
	while (i < sizeof(delimiters))
	{
		if (delimiters[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_boolean	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

t_boolean	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}
