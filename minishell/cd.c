/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:01:39 by omechri           #+#    #+#             */
/*   Updated: 2022/11/28 16:28:38 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fct_cd(t_mini *mini, char **cmd, int length)
{
	char	cwd[256];

	if (length < 2)
	{
		ft_putendl_fd("error: parameter not known", 2);
		return (1);
	}
	if (length > 2)
		return (ft_putendl_fd("cd: too many arguments", 2), 1);
	getcwd(cwd, sizeof(cwd));
	if (chdir(cmd[1]) == 0)
	{
		update_var_env(mini, "OLDPWD", cwd);
		update_var_env(mini, "PWD", cmd[1]);
		return (0);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (1);
	}
}
