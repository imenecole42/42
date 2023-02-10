#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
int	ft_no_path(char  **env)
{

	int		i;

	i = 0;
	while ((env[i]) && !ft_strnstr(env[i], "PATH", 4))
		i++;
	return (i);
}
char	**ft_get_path(char  **env)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}
char	*get_cmd(char *cmd, char **envp)
{

	char 	**paths;
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i=ft_no_path(envp);
	//printf("%d",i);
	//printf("%d",ft_strlen_mat(envp));
	if(i==ft_strlen_mat(envp))
	{
		write(2,"No such file or directory",25);
		return(0);
	}
	else
	{
		paths = ft_get_path(envp);
		i = -1;
		while (paths[++i])
		{
			slash = ft_strjoin(paths[i], "/");
			path = ft_strjoin(slash, cmd);
			//free(slash);
			if (!access(path, F_OK))
			{
				ft_free(paths);
				return (path);
			}
			//free(path);
		}
		ft_free(paths);
	}
	return (0);
}
int exec_cmd(t_list *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->previous && cmd->previous->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (exit_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (exit_fatal());
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE
			&& dup2(cmd->pipes[SIDE_IN], STDOUT) < 0)
			return (exit_fatal());
		if (cmd->previous && cmd->previous->type == TYPE_PIPE
			&& dup2(cmd->previous->pipes[SIDE_OUT], STDIN) < 0)
			return (exit_fatal());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->args[0]);
			show_error("\n");
		}
		exit(ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[SIDE_OUT]);
		}
		if (cmd->previous && cmd->previous->type == TYPE_PIPE)
			close(cmd->previous->pipes[SIDE_OUT]);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}
/*void	ft_dup(int src, int dest)
{
	dup2(src, 1);
	dup2(dest, 0);
}

void	close_fd(t_pipe *pipex)
{
	ft_close(pipex);
	free_pfd(pipex);
	free(pipex->pid);
	exit(127);
}

void ft_do_redif(t_pipe *pipex)
{
	creat_pipes(pipex);
	fdin = pipe[0];
	fdout = pipe[1];
	if redir_in(pipex)
	{
		close (fdin);
		fdin = redir_in;
	}
	if redir_out(pipex)
	close (fdout);
	fdout = redir_out(pipex);
}

void check_arg(pipex)
{
	check_fd(in et out);
	check_cmd_path();
	get_cmd();
}

void	fork_pipe(t_pipe *pipex, char **argv, char **envp)
{
	ft_do_redif(pipex);
	pipex -> pid[pipex -> i] = fork();
	if (pipex -> pid[pipex -> i] == -1)
		return (write(2, "Error Fork\n", 12), free(NULL));
	if (pipex -> pid[pipex -> i] == 0)
	{
		check_arg(pipex);
		dup2(fdout, 1);
		dup2(fdin, 0);
		if (pipex->cmd[0] && get_cmd(pipex->cmd[0], envp))
		{
			execve(get_cmd(pipex->cmd[0], envp), pipex->cmd, envp);
			ft_free(pipex->cmd);
			free(pipex->pid);
			free_pfd(pipex);
			exit(127);
		}
		else
		{
			ft_putstr_fd(pipex->cmd[0], 2);
			write(2, ": command not found\n", 20);
			ft_free(pipex->cmd);
			free(pipex->pid);
			free_pfd(pipex);
			close(0);
			close(1);
			exit(127);
		}		
	}
	}
}
*/