/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:13:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		error(void)
{
	ft_putstr("\033[32Usage: ./fractol  type\n\n");
	ft_putstr("Available fractals:   * Julia\n");
	ft_putstr("                      * LoopJulia\n");
	ft_putstr("                      * StarJulia\n");
	ft_putstr("                      * CantorJulia\n");
	ft_putstr("                      * Mandelbrot\n");
	ft_putstr("                      * Multibrot\n");
	ft_putstr("                      * Tricorn\n");
	ft_putstr("                      * Douady\n");
	ft_putstr("                      * Feigenbaum\n");
	ft_putstr("                      * Cosine\n");
	ft_putstr("                      * BurningShip\n");
	ft_putstr("                      * SJulia\n");
	ft_putstr("                      * Galaxy\n");
	ft_putstr("                      * LeafJulia\n");
	ft_putstr("                      * InfinityCircles\n");
	exit(-1);
}

void		init_ptr(t_graphic *ptr)
{
	ptr->max_iter = 50;
	ptr->design = 0;
	ptr->intern = 0;
	ptr->zoom = 200;
	ptr->j_cte = complex(-0.7, 0.27015);
	ptr->m_puis = 3;
	ptr->j_puis = 2;
	init_img(ptr);
}

void		init_mouse(t_mouse *mouse)
{
	mouse->x = -2.05;
	mouse->y = -1.3;
	mouse->isclick = 0;
}

void		init_ready(t_ready *r, t_graphic *ptr)
{
	r->width = WIDTH;
	r->height = HEIGHT;
	init_mouse(&(r->mouse));
	r->ptr = ptr;
	r->p = 0;
	r->q = 0;
}

t_complex	complex(double a, double b)
{
	t_complex	z;

	z.re = a;
	z.im = b;
	return (z);
}

float		lerp(float v0, float v1, float t)
{
	return ((1 - t) * v0 + t * v1);
}
