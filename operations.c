/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:28:14 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 19:45:19 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	module(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	max_move(float x, float y)
{
	float	max;

	if (x > y)
		max = x;
	else
		max = y;
	return (max);
}

void	zoom(t_fdf *content, int *z, int *z1)
{
	content->x_axis = content->x_axis * content->zoom;
	content->y_axis = content->y_axis * content->zoom;
	content->x1_axis = content->x1_axis * content->zoom;
	content->y1_axis = content->y1_axis * content->zoom;
	*z *= content->zoom_scale;
	*z1 *= content->zoom_scale;
}

void	shift(t_fdf *content)
{
	content->x_axis = content->x_axis + content->shift_x;
	content->y_axis = content->y_axis + content->shift_y;
	content->x1_axis = content->x1_axis + content->shift_x;
	content->y1_axis = content->y1_axis + content->shift_y;
}
