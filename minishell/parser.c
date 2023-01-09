/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "libft/libft.h"
#include "list.h"
#include "minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int	parse_quoted_string(const char *str, char delimiter)
{
	int	i;

	i = 0;
	while (str[i] != delimiter && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		printf("Error syntax quote %c not found \n", delimiter);
		return (-1);
	}
	return (i);
}

int	parse_string(const char *str)
{
	unsigned int	i;
	int				steps;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_quote(str[i]))
		{
			steps = parse_quoted_string(&str[i + 1], str[i]);
			if (steps < 0)
				return (-1);
			i += steps + 1;
		}
		else if (is_delimiter(str[i]) || is_whitespace(str[i]))
			break ;
		i++;
	}
	return (i - 1);
}

int	is_valid_syntax(t_token current, t_token previous, char *line)
{
	int	status;

	status = 0;
	if (current.id == UNDEFINED_TOKEN)
		status = 2;
	if (previous.id == NONE)
		if (current.id == PIPE)
			status = 2;
	if (previous.id == PIPE)
		if (current.id == PIPE || current.id == END_LINE)
			status = 2;
	if (previous.id == INPUT || previous.id == HEREDOC || previous.id == OUTPUT
		|| previous.id == OUTPUT_APPEND)
		if (current.id != STRING)
			status = 2;
	if (previous.id == END_LINE)
		status = 2;
	if (status == 2)
		printf("invalid sytax near %c\n", line[-1]);
	return (status);
}

void	destroy_token(t_token *token)
{
	if (!token)
		return ;
	if (token->str)
		free(token->str);
	token->str = NULL;
}

int	parse_line(t_mini *mini, t_cmd **command, char *line)
{
	int			status;
	t_tokens	tokens;
	t_cmd		*cmd;
	t_list		*args;

	cmd = make_command();
	*command = cmd;
	args = NULL;
	status = 0;
	tokens.previous = make_token(NONE, NULL);
	while (!status && line)
	{
		tokens.current = get_next_token(&line);
		status = is_valid_syntax(tokens.current, tokens.previous, line);
		if (status == 0)
			status = handle_token(mini, &tokens, &cmd, &args);
		destroy_token(&tokens.previous);
		if (tokens.current.id == END_LINE)
			break ;
		tokens.previous = tokens.current;
	}
	destroy_token(&tokens.current);
	if (status)
		ft_lstclear(&args, free);
	return (status);
}
