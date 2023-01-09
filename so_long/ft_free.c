/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:52:26 by imraoui           #+#    #+#             */
/*   Updated: 2022/10/25 17:56:14 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab(t_data *map)
{
	int	i;

	i = 0;
	while (map -> tab[i])
	{
		free(map -> tab[i]);
		i++;
	}
	free(map -> tab);
}

void	ft_free_path(t_data *map)
{
	int	i;

	i = 0;
	while (map -> path[i])
	{
		free(map -> path[i]);
		i++;
	}
	free(map -> path);
}

void	ft_error_path(t_data *map)
{
	ft_free_path(map);
	ft_free_tab(map);
	free(map);
	ft_putstr("invalid path\n");
	exit (EXIT_FAILURE);
}

void	ft_error(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error extention .ber\n");
	exit (EXIT_FAILURE);
}

void	ft_error1(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error symbol\n");
	exit (EXIT_FAILURE);
}
