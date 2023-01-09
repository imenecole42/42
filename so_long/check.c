/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:36:56 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/07 07:33:16 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_play(t_data *map)
{
	int		i;
	int		j;
	int		count_p;
	char	*line;

	i = 0;
	j = 0;
	count_p = 0;
	while (i < map->height)
	{
		j = 0;
		line = map -> tab[i];
		while (line[j + 1])
		{
			if (line[j] == 'P')
				count_p ++;
			j++;
		}
		i++;
	}
	if ((count_p) != 1)
		return (0);
	return (1);
}

int	ft_check_compt_items(t_data *map)
{
	int		i;
	int		j;
	int		count_c;
	char	*line;

	i = 0;
	j = 0;
	count_c = 0;
	while (i < map -> height)
	{
		j = 0;
		line = map -> tab[i];
		while (line[j + 1])
		{
			if (line[j] == 'C')
				count_c ++;
			j++;
		}
		i++;
	}
	if (count_c == 0)
		return (0);
	return (1);
}

int	ft_check_exit(t_data *map)
{
	int		i;
	int		j;
	int		count_e;
	char	*line;

	i = 0;
	j = 0;
	count_e = 0;
	while (i < map -> height)
	{
		j = 0;
		line = map -> tab[i];
		while (line[j + 1])
		{
			if (line[j] == 'E')
				count_e ++;
			j++;
		}
		i++;
	}
	if (count_e != 1)
		return (0);
	return (1);
}

int	ft_check_symbol(t_data *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (i < map -> height)
	{
		j = 0;
		line = map -> tab[i];
		while (line[j + 1])
		{
			if (!ft_check_caracter(line[j], (const char *)"01CEP"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_matrice(t_data *map)
{
	int	size;
	int	j;
	int	k;

	k = 0;
	j = 0;
	size = ft_strlen(map -> tab[0]);
	map -> width = size - 1;
	while (k < map -> height)
	{
		j = ft_strlen(map -> tab[(k)]);
		if (j != size)
			return (0);
		k++;
	}
	return (1);
}
