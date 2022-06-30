/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:46:02 by rkultaev          #+#    #+#             */
/*   Updated: 2022/06/30 18:16:00 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_content(t_fdf *content)
{
	int	y_axis;

	y_axis = 0;
	while (y_axis < content->height)
	{
		free(content->z_axis[y_axis++]);
	}
	mlx_destroy_image(content->mlx_ptr, content->img);
	mlx_destroy_window(content->mlx_ptr, content->win_ptr);
	free(content->z_axis);
	free(content);
}

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
