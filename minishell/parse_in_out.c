/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_input(t_cmd *command, int fd, char *heredoc_file)
{
	if (command->fd_in > 0)
		close(command->fd_in);
	if (command->heredoc_file)
		unlink(command->heredoc_file);
	command->fd_in = fd;
	command->heredoc_file = heredoc_file;
}

void	change_output(t_cmd *command, int fd)
{
	if (command->fd_out > 0)
		close(command->fd_out);
	command->fd_out = fd;
}

char	*make_file_name(const char *filename_prefix)
{
	struct stat	st;
	char		*filename;
	char		*filename_suffix;
	int			found;
	int			index;

	found = 0;
	index = 0;
	while (!found && index < INT_MAX)
	{
		filename_suffix = ft_itoa(index);
		filename = ft_strjoin(filename_prefix, filename_suffix);
		if (filename_suffix == NULL || filename == NULL)
			return (NULL);
		if (stat(filename, &st) != 0)
			found = 1;
		free(filename_suffix);
		if (!found)
			free(filename);
		index += 1;
	}
	return (filename);
}
