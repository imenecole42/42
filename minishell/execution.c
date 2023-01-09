/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:01:41 by omechri           #+#    #+#             */
/*   Updated: 2022/09/26 11:01:47 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig	g_sig;

int	is_builtins(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo"))
		return (1);
	else if (ft_strcmp(cmd[0], "cd"))
		return (1);
	else if (ft_strcmp(cmd[0], "pwd"))
		return (1);
	else if (ft_strcmp(cmd[0], "export"))
		return (1);
	else if (ft_strcmp(cmd[0], "unset"))
		return (1);
	else if (ft_strcmp(cmd[0], "env"))
		return (1);
	else if (ft_strcmp(cmd[0], "exit"))
		return (1);
	return (0);
}

int	nbr_arg(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

int	ft_builtins(t_mini *mini, char **cmd)
{
	int	length;

	length = nbr_arg(cmd);
	if (ft_strcmp(cmd[0], "echo"))
		return (fct_echo(cmd, length));
	else if (ft_strcmp(cmd[0], "cd"))
		return (fct_cd(mini, cmd, length));
	else if (ft_strcmp(cmd[0], "pwd"))
		return (fct_pwd(length));
	else if (ft_strcmp(cmd[0], "export"))
		return (fct_export(mini, cmd, length));
	else if (ft_strcmp(cmd[0], "unset"))
		return (fct_unset(mini, cmd, length));
	else if (ft_strcmp(cmd[0], "env"))
		return (fct_env(mini, length));
	else if (ft_strcmp(cmd[0], "exit"))
		return (fct_exit(mini, cmd, length));
	return (127);
}

void	execution(t_mini *mini, t_cmd *command, char **env)
{
	int	fd;

	if ((is_builtins(command->cmd) == 1) && command->next == NULL)
	{
		if (command->fd_out > 1)
		{
			fd = dup(STDOUT_FILENO);
			dup2(command->fd_out, STDOUT_FILENO);
		}
		g_sig.status = ft_builtins(mini, command->cmd);
		if (ft_strcmp("exit", command->cmd[0]) == 1)
			printf("exit\n");
		if (command->fd_out > 1)
		{
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
	}
	else
		multi_pipe(mini, command, env);
}
