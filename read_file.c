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
	height = 0;
	line = get_next_line(fd);
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
	line = get_next_line(fd);
	width = count_len(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z, char *line)
{
	char	**strs;
	int		i;

	strs = ft_split(line, ' ');
	i = 0;
	while (strs[i])
	{
		z[i] = ft_atoi(strs[i]);
		i++;
		free(strs[i]);
	}
	free(strs);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **) malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *) malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
