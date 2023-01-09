/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:02:06 by omechri           #+#    #+#             */
/*   Updated: 2022/09/30 18:02:11 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	length_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_option(char *tab)
{
	int	i;

	i = 0;
	if (tab[i] == '-')
	{
		i++;
		while (tab[i] && tab[i] == 'n')
			i++;
		if (tab[i] == '\0' && tab[i - 1] == 'n')
			return (1);
	}
	return (0);
}

int	fct_echo(char **args, int args_count)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (i < args_count && ft_option(args[i]) == 1)
	{
		i++;
		n = 1;
	}
	while (i < args_count)
	{
		ft_putstr_fd(args[i], 1);
		if (i + 1 < args_count)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (n == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
