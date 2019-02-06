/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:12:34 by obelouch         ###   ########.fr       */
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

void		fractal(t_graphic *ptr, t_ready *r)
{
	if (ptr->type == FEIGENBAUM)
		feigenbaum(r);
	if (ptr->type == MANDELBROT)
		mandelbrot(r);
	if (ptr->type == MULTIBROT)
		multibrot(r);
	if (ptr->type == TRICORN)
		tricorn(r);
	if (ptr->type == INFCIRCLE)
	{
		whitescreen(ptr);
		infcircle(point(WIDTH / 2, HEIGHT / 2), (HEIGHT / 2) - ((2 / 100) * HEIGHT), *ptr, ptr->design + 1);
	}
	if (ptr->type == COSINE)
		cosine(r);
	if (ptr->type == BURNSHIP)
		burnship(r);
	if (ptr->type == STAR)
		ptr->j_cte = complex(-0.6, 0.6);
	if (ptr->type == DOUADY)
		ptr->j_cte = complex(-0.123, 0.745);
	if (ptr->type == INTERN)
		ptr->j_cte = complex(-0.285, 0.01);
	if (ptr->type == GALAXY)
		ptr->j_cte = complex(-0.4, 0.6);
	if (ptr->type == SJULIA)
		ptr->j_cte = complex(-0.8, 0.156);
	if (ptr->type == LEAF)
		ptr->j_cte = complex(0.285, 0.013);
	if (ptr->type == CANTOR)
		ptr->j_cte = complex(0.285, 0.01);
	if (ptr->type == LOOP)
		ptr->j_cte = complex(-0.5, 0.64);
	if (ptr->type == JULIA || ptr->type == DOUADY || ptr->type == INTERN || ptr->type == GALAXY )
		julia(r);
	if (ptr->type == SJULIA || ptr->type == LEAF || ptr->type == CANTOR || ptr->type == LOOP)
		julia(r);
	if (ptr->type != INFCIRCLE)
		mlx_put_image_to_window(ptr, ptr->win, ptr->image.void_ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_graphic	ptr;
	t_ready		r;

	r.ptr = &ptr;
	if (ac != 2) 
		error();
	init_ptr(r.ptr);
	init_ready(&r, r.ptr);
	fractal_type(r.ptr, av[1]);
	if ((r.ptr)->type == NONE)
		error();
	(r.ptr)->mlx = mlx_init();
	(r.ptr)->win = mlx_new_window((r.ptr)->mlx, WIDTH, HEIGHT, "Fract'ol obelouch");
	fractal(r.ptr, &r);
	mlx_key_hook((r.ptr)->win, key_event, &r);
	mlx_mouse_hook((r.ptr)->win, mouse_event, &r);
	mlx_mouse_hook((r.ptr)->win, mouse_move, &r);
	mlx_loop((r.ptr)->mlx);
	mlx_destroy_window((r.ptr)->mlx, (r.ptr)->win);
	return (0);
}
