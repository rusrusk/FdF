/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:37:55 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/08 11:53:32 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft42_fdf/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdarg.h>
# include <math.h>

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESCAPE			53
# define ANGLE_UP		13
# define ANGLE_DOWN		1
# define ANGLE_LEFT		0
# define ANGLE_RIGHT	2
# define RESET 			259
# define ZOOM_IN		24
# define ZOOM_OUT		27
# define Z_SCALE_UP		34
# define Z_SCALE_DOWN	31

typedef struct node
{
	float		y_axis;
	float		x_axis;
	float		y1_axis;
	float		x1_axis;
	int			**z_axis;
	int			zoom;
	int			zoom_scale;

	int			**color_map;
	int			color;
	int			color_flag;
	float		angle_x;
	float		angle_y;
	int			width;
	int			height;
	int			shift_x;
	int			shift_y;

	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}		t_fdf;

void	read_file(char *file, t_fdf *content);
void	fill_z_coordinates(int *z_define, char *line);
int		ft_printf(const char *str, ...);
int		ft_count_words(char const *str, char c);	
void	draw(t_fdf *content);
void	error_message(char *message);
void	init_image(t_fdf *content);
void	custom_mlx(t_fdf *content, int x, int y, int color);
void	set_up_color(t_fdf *content, int z, int z1, int flag);
void	key_color(int key, t_fdf *content);
void	free_content(t_fdf *content);
int		keyboard_hook(int key, t_fdf *content);
void	handle_event(t_fdf *content);
void	data_generator(t_fdf *content);
void	string_window(t_fdf *content);

float	module(float i);
float	max_move(float x, float y);
void	zoom(t_fdf *content, int *z, int *z1);
void	shift(t_fdf *content);

#endif