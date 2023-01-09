/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:04:01 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 18:04:11 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fct_pwd(int length)
{
	char	cwd[256];

	length = length;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("error");
	else
		ft_putendl_fd(cwd, 1);
	return (0);
}
