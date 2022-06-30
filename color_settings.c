/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:00:23 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 19:32:46 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_up_color(t_fdf *content, int z_axis, int z_axis1, int flag)
{
	if ((z_axis1 || z_axis) && flag == 0)
		content->color = 0x2f4f4f;
	else if ((z_axis1 || z_axis) && flag == 1)
		content->color = 0xbfff;
	else if ((z_axis1 || z_axis) && flag == 2)
		content->color = 0x98fb98;
	else if ((z_axis1 || z_axis) && flag == 3)
		content->color = 0xffc1c1;
	else if ((z_axis1 || z_axis) && flag == 4)
		content->color = 0xcd1076;
	else if ((z_axis1 || z_axis) && flag == 5)
		content->color = 0xfff68f;
	else if ((z_axis1 || z_axis) && flag == 6)
		content->color = 0xff8247;
	else
		content->color = 0xFFFFFF;
}

void	key_color(int key, t_fdf *content)
{
	if (key == 6)
		content->color_flag = 0;
	else if (key == 7)
		content->color_flag = 1;
	else if (key == 8)
		content->color_flag = 2;
	else if (key == 9)
		content->color_flag = 3;
	else if (key == 11)
		content->color_flag = 4;
	else if (key == 45)
		content->color_flag = 5;
	else if (key == 46)
		content->color_flag = 6;
}

/*
0 = lemon chiffon
1 = dark sky
2 = pale green
3 = rosybrown1
4 = khaki
5 = papaya whip
*/