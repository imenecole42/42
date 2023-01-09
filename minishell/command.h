/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:55:09 by omechri           #+#    #+#             */
/*   Updated: 2022/06/13 15:57:14 by b omechri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "minishell.h"

void	add_command(t_list **list, char *command);
char	**make_command_line(t_list *list);
t_cmd	*make_command(void);
void	destroy_command(t_cmd *cmd);

#endif