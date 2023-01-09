/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_command(t_list **list, char *command)
{
	ft_lstadd_back(list, ft_lstnew(command));
}

char	**make_command_line(t_list *list)
{
	char	**command_line;
	int		list_size;
	int		i;

	list_size = ft_lstsize(list);
	command_line = malloc((list_size + 1) * sizeof(char *));
	ft_memset(command_line, 0, (list_size + 1) * sizeof(char *));
	i = 0;
	while (list)
	{
		command_line[i] = list->content;
		list->content = NULL;
		list = list->next;
		i++;
	}
	command_line[i] = NULL;
	return (command_line);
}

void	destroy_command(t_cmd *cmd)
{
	t_cmd	*next;

	next = cmd;
	if (!next)
		return ;
	while (cmd)
	{
		next = next->next;
		if (cmd->fd_in > 0)
			close(cmd->fd_in);
		if (cmd->fd_out > 0)
			close(cmd->fd_out);
		if (cmd->heredoc_file)
		{
			unlink(cmd->heredoc_file);
			free(cmd->heredoc_file);
		}
		ft_clean_array(cmd->cmd);
		cmd->cmd = NULL;
		free(cmd);
		cmd = next;
	}
}

t_cmd	*make_command(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd)
	{
		cmd->next = NULL;
		cmd->cmd = NULL;
		cmd->heredoc_file = NULL;
		cmd->fd_in = -1;
		cmd->fd_out = -1;
	}
	return (cmd);
}
/*void	print_command_list(t_list *list)
{
	while (list)
	{
		printf("%s", (char *)list->content);
		list = list->next;
	}
}

void	print_command(char **args)
{
	while (*args)
	{
		printf("%s ", *args);
		args++;
	}
	printf("\n");
}

void	print_command_line(t_cmd *cmd)
{
	while (cmd)
	{
		printf("==============================\n");
		printf("in %d\n", cmd->fd_in);
		printf("heredoc %s\n", cmd->heredoc_file);
		printf("out %d\n", cmd->fd_out);
		printf("cmd: ");
		print_command(cmd->cmd);
		cmd = cmd->next;
	}
}*/