/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:49:20 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 11:49:24 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

extern t_sig	g_sig;

/*destroy_command(command);
                command = NULL;
                ft_clean_array(env);
*/

int	test(t_cmd *stct_cmd, char **env)
{
	struct stat		st;
	int				r;
	unsigned int	mode;
	char			*command;

	command = stct_cmd->cmd[0];
	r = lstat(command, &st);
	mode = st.st_mode & S_IFMT;
	if (ft_strchr(command, '/') != NULL)
	{
		if (access(command, F_OK & X_OK) == 0)
			execve(command, stct_cmd->cmd, env);
		if (r == -1)
			return (err_msg(NULL, command, "No such file or directory"), 127);
		if (access(command, X_OK) == 0 && (mode != S_IFLNK || mode != S_IFREG))
			return (err_msg(NULL, command, "Is a directory"), 126);
		if (access(command, X_OK) != 0)
			return (err_msg(NULL, command, "Permission denied"), 126);
	}
	else if (access(command, F_OK & X_OK) == 0)
		return (execve(command, stct_cmd->cmd, env), 127);
	else
		return (fonction_execv(search_path(stct_cmd->cmd, env), stct_cmd, env),
			127);
	return (0);
}

int	child(t_mini *mini, t_cmd *struct_cmd, char **env)
{
	if (struct_cmd->cmd[0][0] == '\0' || struct_cmd->cmd == NULL)
	{
		if (struct_cmd->cmd)
			free(struct_cmd->cmd);
		exit(EXIT_FAILURE);
	}
	if (is_builtins(struct_cmd->cmd) == 1)
		g_sig.status = ft_builtins(mini, struct_cmd->cmd);
	else
		g_sig.status = test(struct_cmd, env);
	destroy_command(struct_cmd);
	ft_clean_array(env);
	mini_free(mini);
	exit(g_sig.status);
	return (0);
}

void	pre_child(int fd_in, t_cmd *struct_cmd, int p[2])
{
	if (struct_cmd->fd_in > 0)
	{
		dup2(struct_cmd->fd_in, 0);
		if (fd_in != 0)
			close(fd_in);
	}
	else
	{
		if (fd_in != 0)
		{
			dup2(fd_in, 0);
			close(fd_in);
		}
	}
	if (struct_cmd->fd_out > 1)
		dup2(struct_cmd->fd_out, 1);
	else if (struct_cmd->next != NULL)
		dup2(p[1], 1);
	close(p[1]);
	close(p[0]);
}

void	parent(t_cmd *struct_cmd, int p[2], int *fd_in)
{
	int	status;
	int	w_pid;

	close(p[1]);
	*fd_in = p[0];
	if (struct_cmd->next == NULL)
	{
		close(*fd_in);
		status = -1;
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			w_pid = waitpid(g_sig.pid, &status, 0);
			if (w_pid < 0)
				break ;
		}
		wait(NULL);
		if (WIFEXITED(status))
			g_sig.status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_sig.status = 128 + WTERMSIG(status);
	}
}

int	multi_pipe(t_mini *mini, t_cmd *struct_cmd, char **env)
{
	int	p[2][2];
	int	fd_in;
	int	pipe_idx;

	fd_in = 0;
	pipe_idx = 0;
	while (struct_cmd != NULL)
	{
		pipe(p[pipe_idx]);
		g_sig.pid = fork();
		if (g_sig.pid == -1)
			exit(EXIT_FAILURE);
		else if (g_sig.pid == 0)
		{
			pre_child(fd_in, struct_cmd, p[pipe_idx]);
			child(mini, struct_cmd, env);
		}
		else
		{
			parent(struct_cmd, p[pipe_idx], &fd_in);
			struct_cmd = struct_cmd->next;
			pipe_idx = (pipe_idx + 1) & 1;
		}
	}
	return (-1);
}
