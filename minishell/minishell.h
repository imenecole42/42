/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:55:09 by omechri           #+#    #+#             */
/*   Updated: 2022/06/13 15:57:14 by b omechri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "list.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_boolean
{
	FALSE,
	TRUE
}					t_boolean;

typedef enum e_token_id
{
	INPUT = 0,
	HEREDOC = 1,
	OUTPUT = 2,
	OUTPUT_APPEND = 3,
	PIPE = 4,
	STRING = 5,
	SPACING = 6,
	END_LINE = 7,
	NONE = 8,
	UNDEFINED_TOKEN = -1
}					t_token_id;

typedef struct s_token
{
	t_token_id		id;
	char			*str;
}					t_token;

typedef struct s_sig
{
	pid_t			pid;
	int				exit_step;
	int				status;
}					t_sig;

typedef struct s_cmd
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	char			*heredoc_file;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_env
{
	char			*name;
	char			*value;
}					t_env;

typedef struct s_tokens
{
	t_token			current;
	t_token			previous;
}					t_tokens;

typedef struct s_mini
{
	t_list			*list;
	int				exit;
}					t_mini;

int					ft_strcmp(char *str1, char *str2);
int					init_env(t_mini *mini, char **env);
int					fct_echo(char **args, int args_count);
int					fct_cd(t_mini *mini, char **cmd, int length);
int					fct_pwd(int length);
int					fct_export(t_mini *mini, char **cmd, int length);
int					fct_unset(t_mini *mini, char **cmd, int length);
int					fct_env(t_mini *mini, int length);
int					fct_exit(t_mini *mini, char **cmd, int length);
void				add_var_env(t_mini *mini, char *name, char *value);
int					update_var_env(t_mini *mini, char *name, char *value);
int					is_valid(char *str);
char				*load_env_name(char *src);
char				*load_env_value(char *str);
void				fonction_execv(char **mypaths, t_cmd *struct_cmd,
						char **env);
char				**search_path(char **cmd_args, char **env);
int					heredoc(t_mini *mini, char *delimeter, const char *in_file,
						int *fd_out);
void				destroy_command(t_cmd *cmd);
t_boolean			is_quote(char c);
t_boolean			is_delimiter(char c);
int					multi_pipe(t_mini *mini, t_cmd *struct_cmd, char **env);
void				mini_free(t_mini *mini);
int					is_builtins(char **cmd);
int					ft_builtins(t_mini *mini, char **cmd);
char				**envlist_to_strings(t_mini *mini);
void				ft_clean_array(char **array);
char				*pre_expand(t_mini *mini, char *str);
char				*concat_strs(char *result, char *before_str,
						char *expanded_str);
char				*expand(t_mini *mini, char *str);
char				*expand_variable_name(t_mini *mini, char *var_name);
int					handle_token(t_mini *mini, t_tokens *tokens,
						t_cmd **command, t_list **args);
void				execution(t_mini *mini, t_cmd *command, char **env);
void				err_msg(char *reason, char *command, char *message);
int					parse_line(t_mini *mini, t_cmd **command, char *line);
char				*get_variable_name(const char *str, int *counter);
char				*search_expansion_value(t_mini *mini, char *str_in);
void				change_input(t_cmd *command, int fd, char *heredoc_file);
void				change_output(t_cmd *command, int fd);
char				*make_file_name(const char *filename_prefix);
void				destroy_token(t_token *token);
t_token				get_next_token(char **line);
t_token				make_token(t_token_id id, char *str);
int					parse_string(const char *str);
t_boolean			is_whitespace(char c);
#endif