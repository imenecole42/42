/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:01:57 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/25 17:25:24 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (str[size - 1] == 'r' && str[size - 2] == 'e'
		&&str[size - 3] == 'b' && str[size - 4] == '.')
		return (1);
	return (0);
}

void	ft_pos_player(t_data *map, int *x, int *y)
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
			if (line[j] == 'P')
			{
				*x = i;
				*y = j;
			}
		j++;
		}
	i++;
	}
}

/*
void	ft_print_matrice(t_data *map, char **matrice)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map -> height)
	{
		while (j < map -> width)
		{
			printf("%c", matrice[i][j]);
			j++;
		}
		printf("\n");
		i++ ;
		j = 0;
	}
}
*/
void	ft_null_map(char *path, t_data *map)
{
	int	i;

	i = 0;
	while (i < map -> width)
	{
		path[i] = '0';
		i++;
	}
	path[i] = '\0';
}

void	ft_check_collect(t_data *map)
{
	int	i;

	i = 0;
	map -> path = (char **) malloc(sizeof(char *) * (map -> height + 1));
	map -> path[map -> height] = NULL;
	while (i < map -> height)
	{
		map -> path[i] = (char *) malloc(sizeof(char) * (map -> width + 1));
		ft_null_map(map -> path[i], map);
		i++;
	}
	map -> path[i] = NULL;
}
