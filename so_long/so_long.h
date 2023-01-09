/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:17:30 by imraoui           #+#    #+#             */
/*   Updated: 2022/11/04 11:44:59 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libs/get_next_line.h"
# include "libs/libft.h"
# include "libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# define IMG_DIMENSION 80

typedef struct s_data
{
	char	**tab;
	char	**path;
	int		width;
	int		height;
	int		img;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*space;
	void	*wall;
	void	*play;
	void	*exit;
	void	*collect;
	void	*exits;
	void	*ennemi;
	void	*img0;
	void	*img1;
	void	*imgp;
	void	*imge;
	void	*imgc;		
	void	*imgs;
}t_data;

void	ft_error(t_data *map);
void	ft_error1(t_data *map);
void	ft_error2(t_data *map);
void	ft_error3(t_data *map);
void	ft_error4(t_data *map);
void	ft_error5(t_data *map);
void	ft_pos_player(t_data *map, int *x, int *y);
void	ft_print_matrice(t_data *map, char **matrice);
void	ft_check_collect(t_data *map);
void	ft_backtacking(t_data *map, int i, int j);
void	ft_pos_exit(t_data *map, int *x, int *y);
void	ft_free_path(t_data *map);
void	ft_free_tab(t_data *map);
void	ft_error_path(t_data *map);
void	ft_error(t_data *map);
void	ft_error1(t_data *map);
void	ft_error2(t_data *map);
void	ft_error3(t_data *map);
void	ft_error4(t_data *map);
void	ft_error5(t_data *map);
void	ft_items(t_data *map);
void	ft_erreur_items(t_data *map);
void	ft_print_map(t_data *map);
void	ft_error6(t_data *map);
void	ft_error_path_collect(t_data *map);
void	destroy_mlx(t_data *mlx);
void	get_filename(t_data	*mlx);
void	destroy_image_from_xpm_file(t_data *mlx, int i);
void	ft_put_image_to_window(int y, int x, t_data *mlx);
void	print_img(t_data *mlx);
void	ft_free_ptr(t_data *mlx);
void	ft_free_win(t_data *mlx);
void	get_xpm_fille(t_data *mlx);
void	ft_check_map(t_data *map);
int		ft_check_symbol(t_data *map);
int		ft_check_play(t_data *map);
int		ft_check_c(t_data *map);
int		ft_check_exit(t_data *map);
int		ft_check_matrice(t_data *map);
int		ft_compt_wall(t_data *map);
int		ft_check_wall(t_data *map);
int		ft_check_ber(char *str);
int		ft_path(t_data *map, int i, int j);
int		ft_check_items(t_data *map);
int		ft_check_compt_items(t_data *map);
int		handle_keyrelease(int keysym, t_data *mlx);
int		handle_destroynotify(t_data *mlx);
int		display_map(t_data *mlx);
int		fdir(int pos, char coor, char dir);
int		update_map(t_data *map, int y, int x, char dir);
int		move_map(t_data *mlx, char dir);
int		get_xpm_file(t_data *mlx);
int		ft_check_caracter(char c, char const *str);
#endif
