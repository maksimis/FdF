#include "fdf.h"

#define MAX(a, b) (a > b ? a : b)

float	mod(float x)
{
	return (i < 0) ? -x : x;
}
void	bresenham(float x1, float y1, float x2, float y2, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x2 - x1;
	y_step = y2 - y1;
	max = MAX(mod(x_step), mod(y_step));
	x_step = x_step/max;
	y_step = y_step/max;
	while ((int) (x1 - x2) || (int) (y1 - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, 0xffffff);
		x += x_step;
		y += y_step;
	}

}