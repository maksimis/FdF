/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	tryam1(int x, int y, t_fdf *data)
{
	data->x1 = x;
	data->y1 = y;
}

void	tryam2(int x, int y, t_fdf *data)
{
	data->x2 = x;
	data->y2 = y;
}

void	draw_background(t_fdf *fdf)
{
	int	i;
	int	*img;

	i = 0;
	img = (int *)(fdf->addr);
	while (i < SCRN_HEIGHT * SCRN_HEIGHT)
	{
		img[i] = 0x00;
		++i;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				tryam1(x, y, data);
				tryam2(x + 1, y, data);
				bresenham(data);
			}
			if (y < data->height - 1)
			{
				tryam1(x, y, data);
				tryam2(x, y + 1, data);
				bresenham(data);
			}
			x++;
		}
		y++;
	}
}
