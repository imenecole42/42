/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:51:07 by hferjani          #+#    #+#             */
/*   Updated: 2023/02/03 16:21:11 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "Libft/libft.h"
#include "Libft/get_next_line.h"
#include <string.h>

typedef struct s_data
{
        char    **env;
        char    **export;
        int     argc;
} t_data;

int  creat_env(char **env,t_data *mini);
void realloc_env (t_data *mini,char *str);
void ft_print_export(t_data *mini,char **argv);
int  ft_env(t_data *mini);
int  print_export(t_data *mini);
int  creat_export(t_data *mini);
void realloc_export(t_data *mini,char *str);
void realloc_export_be(t_data *mini, char *str);
void get_export(t_data *mini,char **argv);
void get_env(t_data *mini,char **argv);
int  print_export(t_data *mini);
int	ft_echo(char **argv, t_data *mini);
int  ft_check(char *argv);
char *ft_get_add_export(t_data *mini,char *str);
char *ft_get_add_env(t_data *mini,char *str);
void ft_export(char **argv,t_data *mini);
void ft_free(char **str);
int  is_plus(char *str);
int  is_export(char *str);
char *strdup_plus(char *str);
char *ft_select(char *str);
char *ft_select1(char *str);
char *ft_select2(char *str);
void realloc_env_be(t_data *mini, char *str);
void realloc_unset(t_data *mini,char *str);
void ft_unset(t_data *mini,char *str);
int strlen_env(t_data *mini,char *str);
int	ft_pwd(t_data *mini);
int	get_var(char *var, char **env);
int	strjoint_env(char *var, char *path, t_data *mini);
char	*get_home(char *var, t_data *mini);
int	cd_new_path(char **cmd, int i, t_data *mini, char *newpath);
int	ft_cd(char **cmd, int argc, t_data *mini);
int	is_exit(char *str);
void	ft_many_arg(t_data *mini);
void	ft_exit(t_data *mini, char **cmd);
int	is_builtin(t_data *mini, char **argv);
int	builtin_env(char **argv);
#endif
