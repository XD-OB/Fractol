/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/06 20:28:23 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fractal_type(t_fractol *r, char *str)
{
	if (!strcmp(str, "Mandelbrot"))
		r->type = MANDELBROT;
	else if (!strcmp(str, "Multibrot"))
		r->type = MULTIBROT;
	else if (!strcmp(str, "Tricorn"))
		r->type = TRICORN;
	else if (!strcmp(str, "Julia"))
		r->type = JULIA;
	else if (!strcmp(str, "StarJulia"))
		r->type = STAR;
	else if (!strcmp(str, "LoopJulia"))
		r->type = LOOP;
	else if (!strcmp(str, "Douady"))
		r->type = DOUADY;
	else if (!strcmp(str, "Feigenbaum"))
		r->type = FEIGENBAUM;
	else if (!strcmp(str, "Cosine"))
		r->type = COSINE;
	else if (!strcmp(str, "BurningShip"))
		r->type = BURNSHIP;
	else if (!strcmp(str, "InfinityCircles"))
		r->type = INFCIRCLE;
	else if (!strcmp(str, "LeafJulia"))
		r->type = LEAF;
	else if (!strcmp(str, "CantorJulia"))
		r->type = CANTOR;
	else if (!strcmp(str, "Galaxy"))
		r->type = GALAXY;
	else if (!strcmp(str, "InternJulia"))
		r->type = INTERN;
	else if (!strcmp(str, "SJulia"))
		r->type = SJULIA;
	else
		r->type = NONE;
}

void		fractal(t_fractol *r)
{
	if (r->type == FEIGENBAUM)
		feigenbaum(r);
	if (r->type == MANDELBROT)
		mandelbrot(r);
	if (r->type == MULTIBROT)
		multibrot(r);
	if (r->type == TRICORN)
		tricorn(r);
	if (r->type == INFCIRCLE)
	{
		whitescreen(r->ptr);
		infcircle(point(WIDTH / 2, HEIGHT / 2), (HEIGHT / 2) - ((2 / 100) * HEIGHT), *(r->ptr), r->ptr->design + 1);
	}
	if (r->type == COSINE)
		cosine(r);
	if (r->type == BURNSHIP)
		burnship(r);
	if (r->type == STAR)
		r->ptr->j_cte = complex(-0.6, 0.6);
	if (r->type == DOUADY)
		r->ptr->j_cte = complex(-0.123, 0.745);
	if (r->type == INTERN)
		r->ptr->j_cte = complex(-0.285, 0.01);
	if (r->type == GALAXY)
		r->ptr->j_cte = complex(-0.4, 0.6);
	if (r->type == SJULIA)
		r->ptr->j_cte = complex(-0.8, 0.156);
	if (r->type == LEAF)
		r->ptr->j_cte = complex(0.285, 0.013);
	if (r->type == CANTOR)
		r->ptr->j_cte = complex(0.285, 0.01);
	if (r->type == LOOP)
		r->ptr->j_cte = complex(-0.5, 0.64);
	if (r->type == JULIA || r->type == DOUADY || r->type == INTERN || r->type == GALAXY)
		julia(r);
	if (r->type == SJULIA || r->type == LEAF || r->type == CANTOR || r->type == LOOP)
		julia(r);
	if (r->type != INFCIRCLE)
		mlx_put_image_to_window(r->ptr, r->ptr->win, r->ptr->image.void_ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_graphic	ptr;
	t_fractol	r;

	r.ptr = &ptr;
	if (ac != 2)
		error();
	init_ptr(r.ptr);
	init_fractol(&r, r.ptr);
	fractal_type(&r, av[1]);
	if (r.type == NONE)
		error();
	if (r.type == JULIA)
		menu_julia();
	if (r.type == MANDELBROT)
		menu_mandel();
	(r.ptr)->mlx = mlx_init();
	(r.ptr)->win = mlx_new_window((r.ptr)->mlx, WIDTH, HEIGHT, "Fract'ol obelouch");
	fractal(&r);
	mlx_key_hook((r.ptr)->win, key_event, &r);
	mlx_mouse_hook((r.ptr)->win, mouse_event, &r);
	mlx_hook((r.ptr)->win, 6, 1L << 6, mouse_move, &r);
	mlx_hook((r.ptr)->win, 17, 1L << 17, win_close, &r);
	mlx_hook((r.ptr)->win, 2, 1L << 2, key_press, &r);
	mlx_loop((r.ptr)->mlx);
	return (0);
}
