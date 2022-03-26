/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:25:55 by cmichael          #+#    #+#             */
/*   Updated: 2022/03/19 08:56:18 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <sys/types.h>
# include	"mlx/mlx.h"
# include	"libft/libft.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		left;
	int		top;
	double	rotate_x;
	double	rotate_y;
	float	x1;
	float	x2;
	float	y1;
	float	y2;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

int		read_file(char *file_name, t_fdf *data);
void	bresenham(t_fdf *data);
void	draw(t_fdf *data);
float	mod(float x);
float	max(float a, float b);
void	iso(float *x, float *y, int z, t_fdf *data);

#endif //FDF_H
