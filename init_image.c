/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:28 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 19:23:48 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_image(t_fdf *content)
{
	content->mlx_ptr = mlx_init();
	content->win_ptr = mlx_new_window(content->mlx_ptr, \
					WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	content->img = mlx_new_image(content->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	content->addr = mlx_get_data_addr(content->img, &content->bits_per_pixel, \
					&content->line_length, &content->endian);
}

void	custom_mlx(t_fdf *content, int x, int y, int color)
{
	char	*ptr;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		ptr = content->addr + (y * content->line_length + \
							x * (content->bits_per_pixel / 8));
		*(unsigned int *)ptr = color;
	}
}
