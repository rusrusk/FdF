/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:05:57 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/08 12:05:53 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	find_height(char	*file)
{
	int		file_descriptor;
	int		height;
	char	*line;

	file_descriptor = open(file, O_RDONLY, 0);
	if (file_descriptor == -1)
		error_message("Error");
	line = get_next_line(file_descriptor);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(file_descriptor);
	}
	free(line);
	close(file_descriptor);
	return (height);
}

int	find_width(char *file)
{
	char	*line;
	int		file_descriptor;
	int		width;

	file_descriptor = open(file, O_RDONLY, 0);
	if (file_descriptor == -1)
		error_message("Error");
	line = get_next_line(file_descriptor);
	width = ft_count_words(line, ' ');
	free(line);
	close(file_descriptor);
	return (width);
}

void	fill_z_axis(int *z_line, char *line)
{
	char	**ptr;
	int		i;
	int		j;

	ptr = ft_split(line, 32);
	i = 0;
	while (ptr[i])
	{
		z_line[i] = ft_atoi(ptr[i]);
		i++;
	}
	j = 0;
	while (ptr[j])
		free(ptr[j++]);
	free(ptr);
}

void	read_file(char *file, t_fdf *content)
{
	int		file_descriptor;
	int		i;
	char	*line;	

	file_descriptor = open(file, O_RDONLY, 0);
	content->height = find_height(file);
	content->width = find_width(file);
	content->z_axis = (int **)malloc(sizeof(int *) * (content->height + 1));
	i = 0;
	while (i < content->height)
	{
		content->z_axis[i] = (int *)malloc(sizeof(int) * (content->width));
		line = get_next_line(file_descriptor);
		fill_z_axis(content->z_axis[i], line);
		free(line);
		i++;
	}
	content->z_axis[i] = NULL;
	close(file_descriptor);
}

/*
	int x = 0;
    int y = 0;

    while(y < content->height)
    {
        x = 0;
        while(x < content->width)
        {
            fprintf(stderr, "%d ", content->z_axis[y][x]);
            x++;
        }
        fprintf(stderr, "%c", '\n');
        y++;
*/

/*
After opening the file, utilize get_next_line() function to read each 
processed line and pass it to helper functions to generate rows based on the 
data received and add them to the map points array.
*/