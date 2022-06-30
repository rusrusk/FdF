/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:11:38 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 19:40:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	string_window(t_fdf *content)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	x = 15;
	y = 0;
	mlx = content->mlx_ptr;
	win = content->win_ptr;
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Move: <- / ^ / v / ->");
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Zoom: + / -");
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Rotate: W / A / S / D");
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Color: Y / X / C / V / B");
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Z_Altitude: I / O");
	mlx_string_put(mlx, win, x, y += 30, 0xffa07a, "Exit: ESC");
}
