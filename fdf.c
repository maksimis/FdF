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

void	bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
	float	x_step;
	float	y_step;
	float	max_step;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max_step = max(mod(x_step), mod(y_step));
	x_step = x_step / max_step;
	y_step = y_step / max_step;
	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, 0xffffff);
		x1 += x_step;
		y1 += y_step;
	}
}
