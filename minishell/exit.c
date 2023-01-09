/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omechri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:29:37 by omechri           #+#    #+#             */
/*   Updated: 2022/10/26 17:29:40 by omechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig	g_sig;

int	verif_limit(char *string)
{
	char	*limit_max;
	int		i;
	int		j;

	i = 0;
	j = 0;
	limit_max = "9223372036854775807";
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (string[i] > limit_max[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

long long	calculate_num(char *string)
{
	int			sig;
	long long	rslt;
	int			i;

	sig = 1;
	rslt = 0;
	i = 0;
	if (string[i] == '-')
		sig = -1;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		rslt = (string[i] - '0') + rslt * 10;
		i++;
	}
	return (rslt * sig);
}

long long	a_to_long_long(char *string, int *exceeding)
{
	long long	rslt;
	char		*new_string;

	if (string[0] != '-' && string[0] != '+')
		new_string = ft_strjoin("+", string);
	else
		new_string = ft_strdup(string);
	if (ft_strlen(new_string) > 20)
	{
		err_msg(new_string, "exit", "numeric argument required\n");
		*exceeding = 1;
	}
	else if (ft_strlen(new_string) == 20)
	{
		if (verif_limit(new_string) == 0)
			rslt = calculate_num(string);
		else
		{
			err_msg(new_string, "exit", "numeric argument required\n");
			*exceeding = 1;
		}
	}
	else
		rslt = calculate_num(new_string);
	return (free(new_string), rslt);
}

int	accepted_format(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i])
	{
		if (string[i] < 48 || string[i] > 57)
		{
			err_msg(string, "exit", "numeric argument required\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	fct_exit(t_mini *mini, char **cmd, int length)
{
	int			exceeding;
	long long	rslt;

	exceeding = 0;
	mini->exit = 1;
	rslt = 0;
	if (length >= 2)
	{
		if (accepted_format(cmd[1]) == -1)
			return (2);
		else
		{
			rslt = a_to_long_long(cmd[1], &exceeding);
			if (exceeding == 1)
				return (2);
		}
	}
	if (length >= 3)
		return (err_msg(NULL, "exit", "too many arguments\n"), 1);
	rslt = rslt % 256;
	if (rslt < 0)
		rslt = rslt + 256;
	return (rslt);
}
