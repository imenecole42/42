/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_id	get_token(const char *str)
{
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '<' && str[1] == '<')
		return (HEREDOC);
	if (str[0] == '<')
		return (INPUT);
	if (str[0] == '>' && str[1] == '>')
		return (OUTPUT_APPEND);
	if (str[0] == '>')
		return (OUTPUT);
	if (str[0] == '\0')
		return (END_LINE);
	if (is_whitespace(str[0]))
		return (SPACING);
	return (STRING);
}

int	get_token_length(t_token_id token)
{
	if (token == HEREDOC || token == OUTPUT_APPEND)
		return (2);
	if (token == STRING)
		return (0);
	return (1);
}

t_token	make_token(t_token_id id, char *str)
{
	t_token	token;

	token.id = id;
	token.str = NULL;
	if (id == STRING)
		token.str = str;
	return (token);
}

t_token	get_next_token_if_string(char **line)
{
	char	*sub_str;
	char	*str;
	int		steps;

	str = *line;
	steps = parse_string(str);
	if (steps < 0)
		return (make_token(UNDEFINED_TOKEN, NULL));
	sub_str = malloc((steps + 2) * sizeof(char));
	if (!sub_str)
		return (make_token(UNDEFINED_TOKEN, NULL));
	ft_memcpy(sub_str, str, steps + 1);
	sub_str[steps + 1] = '\0';
	str += steps + 1;
	*line = str;
	return (make_token(STRING, sub_str));
}

t_token	get_next_token(char **line)
{
	t_token	token;
	char	*str;

	str = *line;
	if (line == NULL || !str || str[0] == '\0')
		return (make_token(END_LINE, NULL));
	token.id = get_token(str);
	while (token.id == SPACING)
	{
		str += get_token_length(token.id);
		token.id = get_token(str);
	}
	if (token.id == STRING)
	{
		*line = str;
		return (get_next_token_if_string(line));
	}
	str += get_token_length(token.id);
	*line = str;
	return (make_token(token.id, NULL));
}
