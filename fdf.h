#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include	"mlx/mlx.h"
#include	"libft/libft.h"

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int 	zoom;
	int 	color;
	int		left;
	int 	top;
	double	rotate_x;
	double	rotate_y;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x1, float y1, float x2, float y2, fdf *data);
void	draw(fdf *data);

#endif //FDF_H

