/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:18:22 by omechri           #+#    #+#             */
/*   Updated: 2022/10/10 15:04:58 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_path_env(char **envp)
{
	int		found;
	int		i;
	char	*paths;

	paths = NULL;
	found = 0;
	i = 0;
	while (found == 0 && envp[i] != 0)
	{
		if (!ft_memcmp(envp[i], "PATH=", 5))
		{
			paths = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			if (paths == NULL)
				return (NULL);
			found = 1;
		}
		i++;
	}
	return (paths);
}

char	**extract_paths(char **envp)
{
	char	*path;
	char	**mypaths;

	path = extract_path_env(envp);
	if (!path)
		return (NULL);
	mypaths = ft_split(path, ':');
	if (path)
		free(path);
	return (mypaths);
}

char	**search_path(char **cmd_args, char **env)
{
	char	**paths;
	int		i;
	char	*tmp;

	i = 0;
	paths = extract_paths(env);
	if (paths == NULL)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		if (!tmp)
			return (NULL);
		paths[i] = ft_strjoin(tmp, cmd_args[0]);
		free(tmp);
		if (!paths[i])
			return (NULL);
		i++;
	}
	return (paths);
}

void	fonction_execv(char **mypaths, t_cmd *struct_cmd, char **env)
{
	int	i;

	i = 0;
	if (mypaths)
	{
		while (mypaths[i])
		{
			if (access(mypaths[i], F_OK & X_OK) == 0)
				execve(mypaths[i], &struct_cmd->cmd[0], env);
			free(mypaths[i]);
			i++;
		}
		free(mypaths);
	}
	write(2, struct_cmd->cmd[0], ft_strlen(struct_cmd->cmd[0]));
	write(2, " : command not found\n", 21);
}
