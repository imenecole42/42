/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:51:07 by hferjani          #+#    #+#             */
/*   Updated: 2023/01/30 16:17:33 by imraoui          ###   ########.fr       */
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
} t_data;

int creat_env(char **env,t_data *mini);
void realloc_env (t_data *mini,char *str);
void ft_print_export(t_data *mini,char **argv);
int  ft_env(t_data *mini);
int print_export(t_data *mini);
int  creat_export(t_data *mini);
void realloc_export(t_data *mini,char *str);
void realloc_export_be(t_data *mini, char *str);
void get_export(t_data *mini,char **argv);
void get_env(t_data *mini,char **argv);
int  print_export(t_data *mini);
int  ft_echo(char **argv,int argc);
int  ft_check(char *argv);
char *ft_get_add_export(t_data *mini,char *str);
char *ft_get_add_env(t_data *mini,char *str);
void ft_export(char **argv,int argc ,t_data *mini);
void ft_free(char **str);
int  is_plus(char *str);
int  is_export(char *str);
char *strdup_plus(char *str);
char *ft_select(char *str);
char *ft_select1(char *str);
void realloc_env_be(t_data *mini, char *str);
#endif
