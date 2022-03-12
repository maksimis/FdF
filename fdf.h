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

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	read_file(char *file_name, fdf *data);

#endif //FDF_H

