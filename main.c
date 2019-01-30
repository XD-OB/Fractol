#include "fractol.h"

static void	error()
{
	ft_putstr("Usage: ./fractol fractal_type\n");
	ft_putstr("Available fractals:	* Julia\n");
	ft_putstr("                     * Mandelbrot\n");
	ft_putstr("                     * Douady Rabbit\n");
	ft_putstr("                     * Dendrite\n");
	ft_putstr("                     * Feigenbaum\n");
	exit(-1);
}

void	init_ptr(t_graphic *ptr)
{
	ptr->max_iter = 120;
	ptr->palette = 0;
	ptr->design = 2;
	palette_color(ptr);
	ptr->zoom = 1;
	ptr->j_cte = complex(-0.7, 0.27015);
	ptr->m_puis = 2;
	init_img(ptr);
}

void	fractal(t_graphic *ptr)
{
	if (ptr->type == FEIGENBAUM)
		feigenbaum(*ptr);
	if (ptr->type == MANDELBROT)
		mandelbrot(*ptr);
	if (ptr->type == DOUADY)
		ptr->j_cte = complex(-0.123, 0.745);
	if (ptr->type == DENDRITE)
		ptr->j_cte = complex(0, 1);
	if (ptr->type == JULIA || ptr->type == DENDRITE || ptr->type == DOUADY)
		julia(*ptr);
	mlx_put_image_to_window(ptr, ptr->win, ptr->image.void_ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_graphic	ptr;

	if (ac != 2 || (ft_strcmp(av[1], "Julia") && ft_strcmp(av[1], "Mandelbrot") && ft_strcmp(av[1], "Douady Rabbit") && ft_strcmp(av[1], "Feigenbaum") && ft_strcmp(av[1], "Dendrite")))
		error();
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "fractol");
	init_ptr(&ptr);
	if (!strcmp(av[1], "Mandelbrot"))
		ptr.type = MANDELBROT;
	if (!strcmp(av[1], "Julia"))
		ptr.type = JULIA;
	if (!strcmp(av[1], "Douady Rabbit"))
		ptr.type = DOUADY;
	if (!strcmp(av[1], "Dendrite"))
		ptr.type = DENDRITE;
	if (!strcmp(av[1], "Feigenbaum"))
		ptr.type = FEIGENBAUM;
	fractal(&ptr);
	mlx_key_hook(ptr.win, key_event, (void*)&ptr);
	mlx_loop(ptr.mlx);
}
