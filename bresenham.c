/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	zoom(t_fdf *data)
{
	data->x1 = data->x1 * data->zoom;
	data->y1 = data->y1 * data->zoom;
	data->x2 = data->x2 * data->zoom;
	data->y2 = data->y2 * data->zoom;
}

void	move(t_fdf *data)
{
	data->x1 = data->x1 + data->left;
	data->y1 = data->y1 + data->top;
	data->x2 = data->x2 + data->left;
	data->y2 = data->y2 + data->top;
}

void	count_step(t_fdf *data, float *x_step, float *y_step)
{
	float	max_step;

	*x_step = data->x2 - data->x1;
	*y_step = data->y2 - data->y1;
	max_step = max(mod(*x_step), mod(*y_step));
	*x_step = *x_step / max_step;
	*y_step = *y_step / max_step;
}

void	img_pix_put(t_fdf *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	bresenham(t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		z1;
	int		z2;

	z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	z2 = data->z_matrix[(int)data->y2][(int)data->x2];
	zoom(data);
	if (z1 || z2)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	iso(&data->x1, &data->y1, z1, data);
	iso(&data->x2, &data->y2, z2, data);
	count_step(data, &x_step, &y_step);
	move(data);
	while ((int)(data->x1 - data->x2) || (int)(data->y1 - data->y2))
	{
		if (data->x1 > 0 && data->x1 < SCRN_WIDTH
			&& data->y1 > 0 && data->y1 < SCRN_HEIGHT)
			img_pix_put(data, data->x1, data->y1, data->color);
		data->x1 += x_step;
		data->y1 += y_step;
	}
}
