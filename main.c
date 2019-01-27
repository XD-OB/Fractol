#include "fractol.h"

static void	error()
{
	ft_putstr("Usage: ./fractol fractal_type\n");
	ft_putstr("Available fractals:	* Julia\n");
	ft_putstr("                     * Mandelbrot\n");
	exit(-1);
}

int	main(int ac, char **av)
{
	t_graphic	ptr;

	if (ac != 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")))
		error();
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "fractol");
	if (!strcmp(av[1], "Mandelbrot"))
	{
		mandelbrot(ptr);
		mlx_loop(ptr.mlx);
	}
}
