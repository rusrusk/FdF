/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:33:23 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/07 20:48:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_generator(t_fdf *content)
{
	content->zoom = 30;
	content->zoom_scale = 2;
	content->color = 0xffec8b;
	content->color_flag = 0;
	content->angle_x = 0.6;
	content->angle_y = 0.6;
	content->shift_x = 600;
	content->shift_y = 400;
	content->x_axis = 0;
	content->x1_axis = 0;
	content->y_axis = 0;
	content->y1_axis = 0;
}	

int	main(int argc, char **argv)
{
	t_fdf	*content;

	if (argc != 2 || !argv[1])
		error_message("Error occured");
	content = (t_fdf *)malloc(sizeof(t_fdf));
	if (!content)
		error_message("Error");
	read_file(argv[1], content);
	data_generator(content);
	init_image(content);
	draw(content);
	mlx_key_hook(content->win_ptr, keyboard_hook, content);
	mlx_loop(content->mlx_ptr);
}
