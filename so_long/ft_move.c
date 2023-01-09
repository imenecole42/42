/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:42:35 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/04 10:46:13 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fdir(int pos, char coor, char dir)
{
	if (dir == 'U' && coor == 'Y')
		return (pos - 1);
	if (dir == 'D' && coor == 'Y')
		return (pos + 1);
	if (dir == 'L' && coor == 'Y')
		return (pos);
	if (dir == 'R' && coor == 'Y')
		return (pos);
	if (dir == 'U' && coor == 'X')
		return (pos);
	if (dir == 'D' && coor == 'X')
		return (pos);
	if (dir == 'L' && coor == 'X')
		return (pos - 1);
	if (dir == 'R' && coor == 'X')
		return (pos + 1);
	return (0);
}

int	update_map(t_data *map, int y, int x, char dir)
{
	if (map->tab[y][x] == 'P'
		&& map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == '0')
	{
		map->tab[y][x] = '0';
		map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'P';
		return (1);
	}
	if (map->tab[y][x] == 'P'
		&& map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == 'C')
	{
		map->tab[y][x] = '0';
		map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'P';
		return (1);
	}
	if (map->tab[y][x] == 'P'
		&& map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] == 'E'
		&& !ft_check_compt_items(map))
	{
		map->tab[y][x] = '0';
		map->tab[fdir(y, 'Y', dir)][fdir(x, 'X', dir)] = 'S';
		return (1);
	}
	return (0);
}

int	move_map(t_data *mlx, char dir)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (mlx->tab[y])
	{
		x = 0;
		while (mlx->tab[y][x])
		{
			if (mlx->tab[y][x] == 'P')
			{
				i = update_map(mlx, y, x, dir);
				print_img(mlx);
				return (i);
			}
			x++;
		}
		y++;
	}
	return (i);
}
