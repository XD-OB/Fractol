#include "fractol.h"

static void		fractal_type(t_graphic *ptr, char *str)
{
	if (!strcmp(str, "Mandelbrot"))
		ptr->type = MANDELBROT;
	else if (!strcmp(str, "Julia"))
		ptr->type = JULIA;
	else if (!strcmp(str, "Douady"))
		ptr->type = DOUADY;
	else if (!strcmp(str, "Feigenbaum"))
		ptr->type = FEIGENBAUM;
	else if (!strcmp(str, "Cosine"))
		ptr->type = COSINE;
	else
		ptr->type = NONE;

}

void		fractal(t_graphic *ptr)
{
	if (ptr->type == FEIGENBAUM)
		feigenbaum(*ptr);
	if (ptr->type == MANDELBROT)
		mandelbrot(*ptr);
	if (ptr->type == COSINE)
		cosine(*ptr);
	if (ptr->type == DOUADY)
		ptr->j_cte = complex(-0.123, 0.745);
	if (ptr->type == JULIA || ptr->type == DOUADY)
		julia(*ptr);
	mlx_put_image_to_window(ptr, ptr->win, ptr->image.void_ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_graphic	ptr;

	if (ac != 2) 
		error();
	init_ptr(&ptr);
	fractal_type(&ptr, av[1]);
	if (ptr.type == NONE)
		error();
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "fractol");
	fractal(&ptr);
	mlx_key_hook(ptr.win, key_event, (void*)&ptr);
	mlx_loop(ptr.mlx);
}
