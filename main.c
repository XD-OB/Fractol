#include "fractol.h"

static void		fractal_type(t_graphic *ptr, char *str)
{
	if (!strcmp(str, "Mandelbrot"))
		ptr->type = MANDELBROT;
	else if (!strcmp(str, "Multibrot"))
		ptr->type = MULTIBROT;
	else if (!strcmp(str, "Tricorn"))
		ptr->type = TRICORN;
	else if (!strcmp(str, "Julia"))
		ptr->type = JULIA;
	else if (!strcmp(str, "StarJulia"))
		ptr->type = STAR;
	else if (!strcmp(str, "LoopJulia"))
		ptr->type = LOOP;
	else if (!strcmp(str, "Douady"))
		ptr->type = DOUADY;
	else if (!strcmp(str, "Feigenbaum"))
		ptr->type = FEIGENBAUM;
	else if (!strcmp(str, "Cosine"))
		ptr->type = COSINE;
	else if (!strcmp(str, "BurningShip"))
		ptr->type = BURNSHIP;
	else if (!strcmp(str, "InfinityCircles"))
		ptr->type = INFCIRCLE;
	else
		ptr->type = NONE;

}

void		fractal(t_graphic *ptr)
{
	if (ptr->type == FEIGENBAUM)
		feigenbaum(ptr);
	if (ptr->type == MANDELBROT)
		mandelbrot(ptr);
	if (ptr->type == MULTIBROT)
		multibrot(ptr);
	if (ptr->type == TRICORN)
		tricorn(ptr);
	if (ptr->type == INFCIRCLE)
	{
		whitescreen(ptr);
		infcircle(point(WIDTH / 2, HEIGHT / 2), (HEIGHT / 2) - ((2 / 100) * HEIGHT), *ptr, ptr->design + 1);
	}
	if (ptr->type == COSINE)
		cosine(ptr);
	if (ptr->type == STAR)
		star(ptr);
	if (ptr->type == LOOP)
		loop(ptr);
	if (ptr->type == BURNSHIP)
		burnship(ptr);
	if (ptr->type == DOUADY)
		ptr->j_cte = complex(-0.123, 0.745);
	if (ptr->type == JULIA || ptr->type == DOUADY)
		julia(ptr);
	if (ptr->type != INFCIRCLE)
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
