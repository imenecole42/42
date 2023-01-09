/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:56:48 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/07 07:51:02 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data	*map)
{
	free(map);
	ft_putstr("invalid fd\n");
	exit(EXIT_FAILURE);
}

void	free_map_tab(t_data *map)
{
	ft_free_path(map);
	ft_free_tab(map);
	free(map);
}

int	count_lines(char *argv, t_data *map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		free_map(map);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		ft_putstr("map enpty\n");
		exit (EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close (fd);
	return (i);
}

void	get_map(int fd, char **argv, t_data *map)
{
	int	i;
	int	size;

	i = 0;
	size = count_lines(argv[1], map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_map(map);
	map->height = size;
	map->tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map->tab)
		return ;
	map -> tab[i] = get_next_line(fd);
	while (map -> tab[i])
	{
		i++;
		map -> tab[i] = get_next_line(fd);
	}
	map -> tab[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*map;
	int		x;
	int		y;
	int		fd;

	fd = 0;
	map = (t_data *)malloc(sizeof(t_data) * 1);
	if (argc == 2)
	{
		get_map(fd, argv, map);
		if (!ft_check_ber(argv[1]))
			ft_error(map);
		ft_check_map(map);
		ft_pos_exit(map, &x, &y);
		if (!ft_path(map, x, y))
			ft_error_path(map);
		ft_items(map);
		if (ft_check_items(map) == 0)
			ft_error_path_collect(map);
		display_map(map);
		free(map);
		return (0);
	}
	return (1);
}
