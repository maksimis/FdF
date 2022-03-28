/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = count_len(line, ' ');
	if (line[ft_strlen(line)-2] == ' ')
		width--;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

void	fill_matrix(int *z, char *line, int width)
{
	char	**strs;
	int		i;

	strs = ft_split(line, ' ');
	i = 0;
	while (i < width)
	{
		z[i] = ft_atoi(strs[i]);
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	full_fill_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	close(fd);
	return (1);
}

int	read_file(char *file_name, t_fdf *data)
{
	int		i;

	data->height = get_height(file_name);
	if (data->height == 0)
		return (-1);
	data->width = get_width(file_name);
	if (data->height == 0)
		return (-1);
	data->z_matrix = (int **) malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->z_matrix[i++] = (int *) malloc(sizeof(int) * (data->width + 1));
	i = full_fill_matrix(file_name, data);
	return (i);
}
