/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:46:38 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/07 07:36:21 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_caracter(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_ptr(t_data *mlx)
{
	ft_free_tab(mlx);
	ft_free_path(mlx);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}

void	ft_free_win(t_data *mlx)
{
	ft_free_tab(mlx);
	ft_free_path(mlx);
	free(mlx->mlx_win);
	free(mlx);
	exit(0);
}

void	get_xpm_fille(t_data *mlx)
{
	int	i;

	i = 0;
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->imge,
			&mlx->img, &mlx->img);
	if (mlx->exit == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
	mlx->space = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img0,
			&mlx->img, &mlx->img);
	if (mlx->space == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
	mlx->play = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->imgp,
			&mlx->img, &mlx->img);
	if (mlx->play == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
}
