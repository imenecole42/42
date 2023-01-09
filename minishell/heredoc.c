/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:56:41 by omechri           #+#    #+#             */
/*   Updated: 2022/10/14 14:56:44 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig	g_sig;

void	sig_init(int sig)
{
	char	c;

	(void)sig;
	if (sig == SIGINT)
	{
		c = '\n';
		g_sig.exit_step = 1;
		g_sig.status = 128 + sig;
		write(STDOUT_FILENO, "\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		ioctl(STDOUT_FILENO, TIOCSTI, &c);
	}
}

int	fill_heredoc_file(t_mini *mini, char *delimeter, int fd_in)
{
	char	*string;
	char	*expanded_str;
	int		done;

	string = NULL;
	expanded_str = NULL;
	done = 0;
	string = readline(">>>>>");
	if (!string)
		return (printf("warning: here-document delimited by %s\n", delimeter),
			1);
	if (!ft_strcmp(delimeter, string))
	{
		expanded_str = pre_expand(mini, string);
		if (expanded_str)
			ft_putendl_fd(string, fd_in);
	}
	else
		done = 1;
	if (string)
		free(string);
	if (expanded_str)
		free(expanded_str);
	return (done);
}

int	heredoc(t_mini *mini, char *delimeter, const char *in_file, int *fd_out)
{
	int	done;
	int	fd_in;

	g_sig.exit_step = 0;
	g_sig.status = 0;
	fd_in = open(in_file, O_CREAT | O_RDWR | O_TRUNC, 0777);
	done = 0;
	signal(SIGINT, sig_init);
	while (g_sig.exit_step == 0 && !done)
	{
		done = fill_heredoc_file(mini, delimeter, fd_in);
	}
	if (g_sig.exit_step != 0)
	{
		close(fd_in);
		fd_in = -1;
	}
	close(fd_in);
	*fd_out = open(in_file, O_RDONLY);
	return (g_sig.status);
}
