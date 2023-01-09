/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtacking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:25:55 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/04 10:10:05 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_backtacking(t_data *map, int i, int j)
{
	if (map -> tab[i][j + 1] != '1' && map -> tab[i][j + 1] != 'E'
		&& map -> path[i][j + 1] != '1')
	{
		map -> path[i][j + 1] = '1';
		ft_backtacking(map, i, j + 1);
	}
	if (map -> tab[i][j - 1] != '1' && map -> tab[i][j - 1] != 'E'
		&& map -> path[i][j - 1] != '1')
	{
		map -> path[i][j - 1] = '1';
		ft_backtacking(map, i, j - 1);
	}
	if (map -> tab[i + 1][j] != '1' && map -> tab[i + 1][j] != 'E'
		&& map -> path[i + 1][j] != '1')
	{
		map -> path[i + 1][j] = '1';
		ft_backtacking(map, i + 1, j);
	}
	if (map -> tab[i - 1][j] != '1' && map -> tab[i - 1][j] != 'E'
		&& map -> path[i - 1][j] != '1')
	{
		map -> path[i - 1][j] = '1';
		ft_backtacking(map, i - 1, j);
	}
}

void	ft_pos_exit(t_data *map, int *x, int *y)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		line = map -> tab[i];
		while (line[j + 1])
		{
			if (line[j] == 'E')
			{
				*x = i;
				*y = j;
			}
		j++;
		}
	i++;
	}
}

int	ft_path(t_data *map, int i, int j)
{
	ft_pos_player(map, &i, &j);
	ft_check_collect(map);
	ft_backtacking(map, i, j);
	ft_pos_exit(map, &i, &j);
	map -> path[i][j] = 'E';
	if (map -> path[i + 1][j] == '1' || map -> path[i - 1][j] == '1'
		|| map -> path[i][j + 1] == '1' || map -> path[i][j - 1] == '1')
		return (1);
	return (0);
}

void	ft_error_path_collect(t_data *map)
{
	ft_free_path(map);
	ft_free_tab(map);
	free(map);
	ft_putstr("invalid path collect\n");
	exit (EXIT_FAILURE);
}
