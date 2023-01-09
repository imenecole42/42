/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:47:40 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/04 11:21:44 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_filename(t_data	*mlx)
{
	mlx->img0 = "./xpm/space.xpm";
	mlx->imgp = "./xpm/play.xpm";
	mlx->img1 = "./xpm/mur.xpm";
	mlx->imge = "./xpm/exit.xpm";
	mlx->imgc = "./xpm/collect.xpm";
	mlx->imgs = "./xpm/exits.xpm";
	mlx->space = NULL;
	mlx->wall = NULL;
	mlx->collect = NULL;
	mlx->exit = NULL;
	mlx->play = NULL;
	mlx->exits = NULL;
}

void	destroy_image_from_xpm_file(t_data *mlx, int i)
{	
	if (mlx->exit != NULL && i > 0)
		mlx_destroy_image(mlx->mlx_ptr, mlx->exit);
	if (mlx->space != NULL && i > 1)
		mlx_destroy_image(mlx->mlx_ptr, mlx->space);
	if (mlx->play != NULL && i > 2)
		mlx_destroy_image(mlx->mlx_ptr, mlx->play);
	if (mlx->wall != NULL && i > 3)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall);
	if (mlx->collect != NULL && i > 4)
		mlx_destroy_image(mlx->mlx_ptr, mlx->collect);
	if (mlx->exits != NULL && i > 5)
		mlx_destroy_image(mlx->mlx_ptr, mlx->exits);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	ft_free_ptr(mlx);
}

int	get_xpm_file(t_data *mlx)
{
	int	i;

	i = 4;
	get_filename(mlx);
	get_xpm_fille(mlx);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->img1,
			&mlx->img, &mlx->img);
	if (mlx->wall == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
	mlx->collect = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->imgc,
			&mlx->img, &mlx->img);
	if (mlx->collect == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
	mlx->exits = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->imgs,
			&mlx->img, &mlx->img);
	if (mlx->exits == NULL)
		destroy_image_from_xpm_file(mlx, i);
	i++;
	return (1);
}

void	ft_put_image_to_window(int y, int x, t_data *mlx)
{
	int	x1;
	int	y2;

	x1 = x * IMG_DIMENSION;
	y2 = y * IMG_DIMENSION;
	if (mlx->tab[y][x] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->space, x1, y2);
	if (mlx->tab[y][x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->wall, x1, y2);
	if (mlx->tab[y][x] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->play, x1, y2);
	if (mlx->tab[y][x] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->collect, x1, y2);
	if (mlx->tab[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->exit, x1, y2);
	if (mlx->tab[y][x] == 'S')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->exits, x1, y2);
}

void	print_img(t_data *mlx)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (mlx->tab[y])
	{
		x = 0;
		while (mlx->tab[y][x])
		{
			ft_put_image_to_window(y, x, mlx);
			x++;
		}
		y++;
	}
}
