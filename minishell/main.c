/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:01:41 by omechri           #+#    #+#             */
/*   Updated: 2022/09/26 11:01:47 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "list.h"
#include "minishell.h"
#include <stdio.h>

t_sig	g_sig;

void	mini_free(t_mini *mini)
{
	t_env	*content;
	t_list	*tmp;

	while (mini->list)
	{
		tmp = (mini->list)->next;
		content = mini->list->content;
		free(content->name);
		free(content->value);
		free(content);
		free((mini->list));
		mini->list = tmp;
	}
}

void	init_mini(t_mini *mini, char **env)
{
	mini->exit = 0;
	mini->list = NULL;
	if (init_env(mini, env) == -1)
		return ;
	g_sig.exit_step = 0;
}

void	sig_int(int sig)
{
	char	c;

	(void)sig;
	if (sig == SIGINT || sig == SIGQUIT)
	{
		c = '\n';
		g_sig.status = 128 + sig;
		ioctl(STDOUT_FILENO, TIOCSTI, &c);
		rl_on_new_line();
	}
}

void	ft_write_prompt(t_mini *mini)
{
	char	*input;
	char	**env;
	t_cmd	*command;

	while (mini->exit == 0)
	{
		command = NULL;
		signal(SIGINT, sig_int);
		input = readline("$");
		if (input == NULL)
			break ;
		if (input[0] != '\0')
		{
			env = envlist_to_strings(mini);
			g_sig.status = parse_line(mini, &command, input);
			if (g_sig.status == 0 && command && command->cmd && command->cmd[0])
				execution(mini, command, env);
			add_history(input);
			destroy_command(command);
			command = NULL;
			ft_clean_array(env);
		}
		free(input);
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **env)
{
	t_mini	mini;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("invalid number of arguments", 2);
		return (1);
	}
	init_mini(&mini, env);
	ft_write_prompt(&mini);
	mini_free(&mini);
	return (g_sig.status);
}
