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
	else if (!strcmp(str, "LeafJulia"))
		ptr->type = LEAF;
	else if (!strcmp(str, "CantorJulia"))
		ptr->type = CANTOR;
	else if (!strcmp(str, "Galaxy"))
		ptr->type = GALAXY;
	else if (!strcmp(str, "InternJulia"))
		ptr->type = INTERN;
	else if (!strcmp(str, "SJulia"))
		ptr->type = SJULIA;
	else
		ptr->type = NONE;
}

void		fractal(t_fractol *r)
{
	if (r->ptr->type == FEIGENBAUM)
		feigenbaum(r);
	if (r->ptr->type == MANDELBROT)
		mandelbrot(r);
	if (r->ptr->type == MULTIBROT)
		multibrot(r);
	if (r->ptr->type == TRICORN)
		tricorn(r);
	if (r->ptr->type == INFCIRCLE)
	{
		whitescreen(r->ptr);
		infcircle(point(WIDTH / 2, HEIGHT / 2), (HEIGHT / 2) - ((2 / 100) * HEIGHT), *(r->ptr), r->ptr->design + 1);
	}
	if (r->ptr->type == COSINE)
		cosine(r);
	if (r->ptr->type == BURNSHIP)
		burnship(r);
	if (r->ptr->type == STAR)
		r->ptr->j_cte = complex(-0.6, 0.6);
	if (r->ptr->type == DOUADY)
		r->ptr->j_cte = complex(-0.123, 0.745);
	if (r->ptr->type == INTERN)
		r->ptr->j_cte = complex(-0.285, 0.01);
	if (r->ptr->type == GALAXY)
		r->ptr->j_cte = complex(-0.4, 0.6);
	if (r->ptr->type == SJULIA)
		r->ptr->j_cte = complex(-0.8, 0.156);
	if (r->ptr->type == LEAF)
		r->ptr->j_cte = complex(0.285, 0.013);
	if (r->ptr->type == CANTOR)
		r->ptr->j_cte = complex(0.285, 0.01);
	if (r->ptr->type == LOOP)
		r->ptr->j_cte = complex(-0.5, 0.64);
	if (r->ptr->type == JULIA || r->ptr->type == DOUADY || r->ptr->type == INTERN || r->ptr->type == GALAXY)
		julia(r);
	if (r->ptr->type == SJULIA || r->ptr->type == LEAF || r->ptr->type == CANTOR || r->ptr->type == LOOP)
		julia(r);
	if (r->ptr->type != INFCIRCLE)
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
	fractal_type(r.ptr, av[1]);
	if ((r.ptr)->type == NONE)
		error();
	if ((r.ptr)->type == JULIA)
		menu_julia();
	if ((r.ptr)->type == MANDELBROT)
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
