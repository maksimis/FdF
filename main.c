#include "fdf.h"

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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
    return(0);
}