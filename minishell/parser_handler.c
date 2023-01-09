/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"

static int	handle_input(t_cmd *command, char *filename)
{
	int	fd_in;

	fd_in = open(filename, O_RDONLY);
	if (fd_in < 0)
	{
		perror(strerror(errno));
		return (1);
	}
	change_input(command, fd_in, NULL);
	return (0);
}

static int	handle_output(t_cmd *command, const char *filename,
		t_boolean is_append)
{
	int	fd_out;

	if (is_append)
		fd_out = open(filename, O_CREAT | O_RDWR | O_APPEND, 0777);
	else
		fd_out = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd_out < 0)
		return (1);
	change_output(command, fd_out);
	return (0);
}

static int	handle_heredoc(t_mini *mini, t_cmd *command, char *delimiter)
{
	int		fd_in;
	char	*filename;
	int		status;

	filename = NULL;
	filename = make_file_name("/tmp/.tmp.minishell.heredoc");
	status = heredoc(mini, delimiter, filename, &fd_in);
	if (status)
	{
		unlink(filename);
		free(filename);
		return (status);
	}
	change_input(command, fd_in, filename);
	return (status);
}

int	handle_if_string(t_mini *mini, t_tokens *tokens, t_cmd **command,
		t_list **args)
{
	char	*expanded_str;
	int		status;

	status = 0;
	expanded_str = pre_expand(mini, tokens->current.str);
	if (tokens->previous.id == INPUT)
		status = handle_input(*command, expanded_str);
	else if (tokens->previous.id == OUTPUT)
		status = handle_output(*command, expanded_str, FALSE);
	else if (tokens->previous.id == HEREDOC)
		status = handle_heredoc(mini, *command, tokens->current.str);
	else if (tokens->previous.id == OUTPUT_APPEND)
		status = handle_output(*command, expanded_str, TRUE);
	else
		add_command(args, ft_strdup(expanded_str));
	free(expanded_str);
	return (status);
}

int	handle_token(t_mini *mini, t_tokens *tokens, t_cmd **command, t_list **args)
{
	int	status;

	status = 0;
	if (tokens->current.id == STRING)
	{
		status = handle_if_string(mini, tokens, command, args);
	}
	else if (tokens->current.id == PIPE)
	{
		(*command)->cmd = make_command_line(*args);
		ft_lstclear(args, NULL);
		(*command)->next = make_command();
		(*command) = (*command)->next;
		*args = NULL;
	}
	else if (tokens->current.id == END_LINE)
	{
		(*command)->cmd = make_command_line(*args);
		(*command)->next = NULL;
		ft_lstclear(args, NULL);
	}
	return (status);
}
