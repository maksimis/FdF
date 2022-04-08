/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_data(t_fdf *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(data->z_matrix[y]);
		y++;
	}
	free(data->z_matrix);
	free(data);
}

int	exit_programm(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126)
		data->top -= 5;
	if (key == 125)
		data->top += 5;
	if (key == 123)
		data->left -= 2;
	if (key == 124)
		data->left += 2;
	if (key == 78)
		data->zoom -= 2;
	if (key == 69)
		data->zoom += 2;
	if (key == 86)
		data->rotate_x += 0.1;
	if (key == 88)
		data->rotate_x -= 0.1;
	if (key == 91)
		data->rotate_y += 0.1;
	if (key == 84)
		data->rotate_y -= 0.1;
	if (key == 53)
		exit_programm(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	init(t_fdf *data)
{
	data->left = 200;
	data->top = 150;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 2000, 2000, "FdF");
	data->zoom = 20;
	data->color = 0xffffff;
	data->rotate_x = 0.8;
	data->rotate_y = 0.8;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 2000, 2000);
	data->addr = mlx_get_data_addr(data->img_ptr,
			&data->bpp, &data->line_len, &data->endian);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		check_file_name(argv[1]);
		if (read_file(argv[1], data) == -1)
			error_and_exit();
		init(data);
		draw_background(data);
		draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr, 0, 0);
		mlx_key_hook(data->win_ptr, deal_key, data);
		mlx_hook(data->win_ptr, 17, 0L, exit_programm, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_putendl_fd("Incorrect count of arguments", 0);
	return (0);
}
