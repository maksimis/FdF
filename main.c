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

int deal_key(int key, void *data)
{
	char *str =  ft_itoa(key);
	write(1, str, ft_strlen(str));
	free(str);
	return (0);
}

int main()
{
    int	a;
void	*mlx;
//void	*win1;
//  printf("MinilibX Test Program\n");
//
//  printf(" => Connection ...");
//  if (!(mlx = mlx_init()))
//    {
//      printf(" !! KO !!\n");
//      exit(1);
//    }
  //printf("OK (use_xshm %d pshm_format %d)\n",((t_xvar *)mlx)->use_xshm,((t_xvar *)mlx)->pshm_format);

//  printf(" => Window1 %dx%d \"Title 1\" ...",300,300);
//  if (!(win1 = mlx_new_window(mlx,300,300,"Title1")))
//    {
//      printf(" !! KO !!\n");
//      exit(1);
//    }
//  printf("OK\n");
//  mlx_pixel_put(mlx, win1, 10, 10, 0xFFFFFF);
//   sleep(10);
	void	*mlx_win;

//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//	mlx_loop(mlx);

	fdf *data;

	data = (fdf *)malloc(sizeof(fdf));
	read_file("test_maps/10-2.fdf", data);

//	int i;
//	int j;
//
//	i = 0;
//	while(i < data->height)
//	{
//		j = 0;
//		while (j < data->width)
//		{
//			deal_key(data->z_matrix[i][j], data);
//			write(1, " ", 1);
//			j++;
//		}
//		write(1, "\n", 1);
//		i++;
//	}


	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FdF");
	bresenham(10, 20, 300, 400, data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
    //return(0);
}