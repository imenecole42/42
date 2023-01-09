/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:12:26 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/04 10:30:06 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keyrelease(int keysym, t_data *mlx)
{
	static int	move;
	int			i;

	if (!move)
		move = 0;
	i = 0;
	if (keysym == XK_Escape)
		destroy_image_from_xpm_file(mlx, 6);
	if (keysym == XK_w || keysym == XK_Up)
		i = move_map(mlx, 'U');
	if (keysym == XK_s || keysym == XK_Down)
		i = move_map(mlx, 'D');
	if (keysym == XK_d || keysym == XK_Right)
		i = move_map(mlx, 'R');
	if (keysym == XK_a || keysym == XK_Left)
		i = move_map(mlx, 'L');
	move = move + i;
	if (i == 1)
	{	
		ft_putstr("number move = ");
		ft_putnbr_fd(move, 1);
		ft_putstr(" \n");
	}
	return (0);
}

int	handle_destroynotify(t_data *mlx)
{
	destroy_mlx(mlx);
	ft_free_tab(mlx);
	ft_free_path(mlx);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}

void	destroy_mlx(t_data *mlx)
{
	destroy_image_from_xpm_file(mlx, 6);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
}

int	display_map(t_data *mlx)
{
	mlx->img = 80;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		ft_free_ptr(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, (mlx->img * mlx->width),
			(mlx->img * mlx->height), "Reine!");
	if (!mlx->mlx_win)
	{
		destroy_mlx(mlx);
		ft_free_win(mlx);
	}
	if (!get_xpm_file(mlx))
	{	
		destroy_mlx(mlx);
		ft_free_ptr(mlx);
	}
	print_img(mlx);
	mlx_hook(mlx->mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, mlx);
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask,
		&handle_destroynotify, mlx);
	mlx_loop(mlx->mlx_ptr);
	exit(1);
}
