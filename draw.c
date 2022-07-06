/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:40:35 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/06 16:16:34 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_scale(int z, int z1, t_fdf *content)
{
	content->x_axis = (int)((content->x_axis - content->y_axis)
			* cos(content->angle_x));
	content->y_axis = (int)((content->x_axis + content->y_axis)
			* sin(content->angle_y) - z);
	content->x1_axis = (int)((content->x1_axis - content->y1_axis)
			* cos(content->angle_x));
	content->y1_axis = (int)((content->x1_axis + content->y1_axis)
			* sin(content->angle_y) - z1);
}

void	united_lines_bresenham(t_fdf *content)
{
	float	x_move;
	float	y_move;
	int		max;
	int		z;
	int		z1;

	z = content->z_axis[(int)content->y_axis][(int)content->x_axis];
	z1 = content->z_axis[(int)content->y1_axis][(int)content->x1_axis];
	zoom(content, &z, &z1);
	set_up_color(content, z, z1, content->color_flag);
	isometric_scale(z, z1, content);
	shift(content);
	x_move = content->x1_axis - content->x_axis;
	y_move = content->y1_axis - content->y_axis;
	max = max_move(module((int)x_move), module((int)y_move));
	x_move = x_move / max;
	y_move = y_move / max;
	while ((int)(content->x_axis - content->x1_axis)
			|| (int)(content->y_axis - content->y1_axis))
	{
		custom_mlx(content, content->x_axis, content->y_axis, content->color);
		content->x_axis = content->x_axis + x_move;
		content->y_axis = content->y_axis + y_move;
	}
}

void	append_coordinates(t_fdf *content, int x, int y, int review)
{
	if (review == 0)
	{
		content->x_axis = x;
		content->y_axis = y;
		content->x1_axis = x + 1;
		content->y1_axis = y;
	}
	else if (review == 1)
	{
		content->x_axis = x;
		content->y_axis = y;
		content->x1_axis = x;
		content->y1_axis = y + 1;
	}
	united_lines_bresenham(content);
}

void	draw(t_fdf *content)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	mlx = content->mlx_ptr;
	win = content->win_ptr;
	y = 0;
	while (y < content->height)
	{
		x = 0;
		while (x < content->width)
		{
			if (x < content->width - 1)
				append_coordinates(content, x, y, 0);
			if (y < content->height - 1)
				append_coordinates(content, x, y, 1);
		x++;
		}
	y++;
	}
	mlx_put_image_to_window(mlx, win, content->img, 0, 0);
	string_window(content);
}

/*
if ((int)content->x_axis < WINDOW_WIDTH
			&& (int)content->y_axis < WINDOW_HEIGHT
			&& (int)content->x_axis >= 0 && (int)content->y_axis >= 0)
*/

/*
	// printf("x is %f\n", content->x_axis);
	// printf("y is %f\n", content->y_axis);
	// printf("x1 is %f\n", content->x1_axis);
	// printf("y1 is %f\n", content->y1_axis);
	// printf("z is %d\n", z);
	// printf("z1 is %d\n", z1);
*/