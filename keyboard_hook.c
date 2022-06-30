/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:34:57 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 18:13:31 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_move(int key, t_fdf *content)
{
	if (key == UP)
		content->shift_y -= 25;
	if (key == DOWN)
		content->shift_y += 25;
	if (key == LEFT)
		content->shift_x -= 25;
	if (key == RIGHT)
		content->shift_x += 25;
	return (0);
}

static int	key_angle(int key, t_fdf *content)
{
	if (key == ANGLE_UP)
		content->angle_y -= (5 * 0.01);
	if (key == ANGLE_DOWN)
		content->angle_y += (5 * 0.01);
	if (key == ANGLE_LEFT)
		content->angle_x -= (5 * 0.01);
	if (key == ANGLE_RIGHT)
		content->angle_x += (5 * 0.01);
	return (0);
}

static int	key_zoom(int key, t_fdf *content)
{
	if (key == ZOOM_IN)
		content->zoom += 1;
	else if (key == ZOOM_OUT)
		content->zoom -= 1;
	return (0);
}

static int	key_z_scale(int key, t_fdf *content)
{
	if (key == Z_SCALE_UP)
		content->zoom_scale += 1;
	else if (key == Z_SCALE_DOWN)
		content->zoom_scale -= 1;
	return (0);
}

int	keyboard_hook(int key, t_fdf *content)
{
	printf("%d\n", key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		key_move(key, content);
	else if (key == ANGLE_UP || key == ANGLE_DOWN || key == ANGLE_LEFT
		|| key == ANGLE_RIGHT)
		key_angle(key, content);
	else if (key == RESET)
		data_generator(content);
	else if (key == 6 || key == 7 || key == 8 || key == 9 || key == 11
		|| key == 45 || key == 46)
		key_color(key, content);
	else if (key == 24 || key == 27)
		key_zoom(key, content);
	else if (key == Z_SCALE_UP || key == Z_SCALE_DOWN)
		key_z_scale(key, content);
	else if (key == ESCAPE)
	{
		free_content(content);
		exit(0);
	}
	handle_event(content);
	draw(content);
	return (0);
}
