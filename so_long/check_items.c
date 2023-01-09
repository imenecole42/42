/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:46:43 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/07 07:35:18 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_compt_wall(t_data *map)
{
	int		j;
	int		count;
	char	*line;

	j = 0;
	count = 1;
	line = map -> tab[0];
	while (line[j])
	{
		if (line[j] == '1')
			count ++;
		j++;
	}
	return (count);
}

int	ft_check_wall(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tab[i])
	{
		j = 0;
		while (j <= map->width - 1)
		{	
			if (map->tab[0][j] != '1' || map->tab[map->height - 1][j] != '1'
				|| map->tab[i][0] != '1' || map->tab[i][map->width - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_check_map(t_data *map)
{
	if (!ft_check_symbol(map))
		ft_error1(map);
	if (!ft_check_play(map))
		ft_error2(map);
	if (!ft_check_exit(map))
		ft_error3(map);
	if (!ft_check_matrice(map))
		ft_error4(map);
	if (!ft_check_wall(map))
		ft_error5(map);
	if (!ft_check_compt_items(map))
		ft_error6(map);
}

void	ft_items(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if (map -> tab[i][j] == 'C' && map -> path[i][j] == '0')
				map -> path[i][j] = 'C';
			j++;
		}
		i++;
	}
}

int	ft_check_items(t_data *map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if (map -> path[i][j] == 'C')
				count_c ++;
			j++;
		}
		i++;
	}
	if (count_c == 0)
		return (1);
	return (0);
}
