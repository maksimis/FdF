/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
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

void	iso(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->rotate_x);
	*y = (*x + *y) * sin(data->rotate_y) - z;
}
