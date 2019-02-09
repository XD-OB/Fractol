/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:02:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 22:19:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		partfract(t_fractol *f)
{
	if (f->type == FEIGENBAUM)
		feigenbaum(f);
	else if (f->type == STAR)
		f->ptr->j_cte = complex(-0.6, 0.6);
	else if (f->type == DOUADY)
		f->ptr->j_cte = complex(-0.123, 0.745);
	else if (f->type == INTERN)
		f->ptr->j_cte = complex(-0.285, 0.01);
	else if (f->type == GALAXY)
		f->ptr->j_cte = complex(-0.4, 0.6);
	else if (f->type == SJULIA)
		f->ptr->j_cte = complex(-0.8, 0.156);
	else if (f->type == LEAF)
		f->ptr->j_cte = complex(0.285, 0.013);
	else if (f->type == CANTOR)
		f->ptr->j_cte = complex(0.285, 0.01);
	else if (f->type == LOOP)
		f->ptr->j_cte = complex(-0.5, 0.64);
	if (f->type == LOOP || f->type == CANTOR || f->type == LEAF ||
			f->type == SJULIA || f->type == GALAXY || f->type == INTERN
			|| f->type == DOUADY || f->type == STAR)
		julia(f);
}

void			fractal(t_fractol *f)
{
	if (f->type == JULIA)
		julia(f);
	else if (f->type == MANDELBROT)
		mandelbrot(f);
	else if (f->type == MULTIBROT)
		multibrot(f);
	else if (f->type == TRICORN)
		tricorn(f);
	else if (f->type == COSINE)
		cosine(f);
	else if (f->type == BURNSHIP)
		burnship(f);
	else if (f->type == INFCIRCLE)
	{
		whitescreen(f->ptr);
		infcircle(point(WIDTH / 2, HEIGHT / 2), (HEIGHT / 2)
				- ((2 / 100) * HEIGHT), *(f->ptr), f->ptr->design + 1);
	}
	else if (f->type == MULTIJULIA)
		multijulia(f);
	partfract(f);
	if (f->type != INFCIRCLE)
		mlx_put_image_to_window(f->ptr, f->ptr->win,
				f->ptr->image.void_ptr, 0, 0);
}

static void		part_fractype(t_fractol *f, char *str)
{
	if (!strcmp(str, "Douady"))
		f->type = DOUADY;
	else if (!strcmp(str, "Feigenbaum"))
		f->type = FEIGENBAUM;
	else if (!strcmp(str, "Cosine"))
		f->type = COSINE;
	else if (!strcmp(str, "BurningShip"))
		f->type = BURNSHIP;
	else if (!strcmp(str, "InfinityCircles"))
		f->type = INFCIRCLE;
	else if (!strcmp(str, "CantorJulia"))
		f->type = CANTOR;
	else if (!strcmp(str, "InternJulia"))
		f->type = INTERN;
	else if (!strcmp(str, "SJulia"))
		f->type = SJULIA;
}

void			fractal_type(t_fractol *f, char *str)
{
	part_fractype(f, str);
	if (!strcmp(str, "Mandelbrot"))
		f->type = MANDELBROT;
	else if (!strcmp(str, "Multibrot"))
		f->type = MULTIBROT;
	else if (!strcmp(str, "Tricorn"))
		f->type = TRICORN;
	else if (!strcmp(str, "Julia"))
		f->type = JULIA;
	else if (!strcmp(str, "MultiJulia"))
		f->type = MULTIJULIA;
	else if (!strcmp(str, "StarJulia"))
		f->type = STAR;
	else if (!strcmp(str, "LoopJulia"))
		f->type = LOOP;
	else if (!strcmp(str, "LeafJulia"))
		f->type = LEAF;
	else if (!strcmp(str, "Galaxy"))
		f->type = GALAXY;
}
