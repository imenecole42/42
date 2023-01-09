/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:23 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/07 07:37:29 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error2(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error player\n");
	exit (EXIT_FAILURE);
}

void	ft_error3(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error exit\n");
	exit (EXIT_FAILURE);
}

void	ft_error4(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error form rectangle\n");
	exit (EXIT_FAILURE);
}

void	ft_error5(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("Error wall\n");
	exit (EXIT_FAILURE);
}

void	ft_error6(t_data *map)
{
	ft_free_tab(map);
	free(map);
	ft_putstr("items is null\n");
	exit (EXIT_FAILURE);
}
/*
void	ft_print_map(t_data *map)
{
	int	i;

	i = 0;
	while (map -> tab[i])
	{
		printf("str%d\n:%s", i, map -> tab[i]);
		i++;
	}
	printf("\n\n");
}
*/
