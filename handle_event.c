/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:13:14 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 18:15:18 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_event(t_fdf *content)
{
	mlx_clear_window(content->mlx_ptr, content->win_ptr);
	mlx_destroy_image(content->mlx_ptr, content->img);
	content->img = mlx_new_image(content->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	content->addr = mlx_get_data_addr(content->img, \
			&content->bits_per_pixel, &content->line_length, &content->endian);
}
