#include "fractol.h"

void	error()
{
	ft_putstr("Usage: ./fractol fractal_type\n");
	ft_putstr("Available fractals:	* Julia\n");
	ft_putstr("                     * Mandelbrot\n");
	exit(-1);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot")))
		error();
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!strcmp(av[1], "Mandelbrot"))
	{
		mlx_loop(mlx_ptr);
	}
}
