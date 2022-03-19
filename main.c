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

int deal_key(int key, fdf *data)
{
	char *str =  ft_itoa(key);
	write(1, str, ft_strlen(str));
	free(str);
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
 	fdf *data;

	 if (argc == 2)
	 {

		 data = (fdf *)malloc(sizeof(fdf));
		 read_file(argv[1], data);
		 data->left = 200;
		 data->top = 150;
		 data->mlx_ptr = mlx_init();
		 data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FdF");
		 data->zoom = 20;
		 data->color = 0xffffff;
		 data->rotate_x = 0.8;
		 data->rotate_y = 0.8;
		 draw(data);
		 mlx_key_hook(data->win_ptr, deal_key, data);
		 mlx_loop(data->mlx_ptr);
	 }
	return (0);
}