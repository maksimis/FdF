/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod(float x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	iso(float *x, float *y, int z, fdf *data)
{
	*x = (*x - *y) * cos(data->rotate_x);
	*y = (*x + *y) * sin(data->rotate_y) - z;
}

void	bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
	float	x_step;
	float	y_step;
	float	max_step;
	int 	z1;
	int 	z2;

	z1 = data->z_matrix[(int)y1][(int)x1];
	z2 = data->z_matrix[(int)y2][(int)x2];
	x1 = x1 * data->zoom;
	y1 = y1 * data->zoom;
	x2 = x2 * data->zoom;
	y2 = y2 * data->zoom;
	if (z1 || z2)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	iso(&x1, &y1, z1, data);
	iso(&x2, &y2, z2, data);
	x_step = x2 - x1;
	y_step = y2 - y1;
	max_step = max(mod(x_step), mod(y_step));
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	x1 = x1 + data->left;
	y1 = y1 + data->top;
	x2 = x2 + data->left;
	y2 = y2 + data->top;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		x1 += x_step;
		y1 += y_step;
	}
}
