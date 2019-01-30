#include "fractol.h"

void		error()
{
	ft_putstr("Usage: ./fractol  type\n\n");
	ft_putstr("Available fractals:   * Julia\n");
	ft_putstr("                      * Mandelbrot\n");
	ft_putstr("                      * Douady\n");
	ft_putstr("                      * Feigenbaum\n");
	exit(-1);
}

void		init_ptr(t_graphic *ptr)
{
	ptr->max_iter = 300;
	ptr->palette = 0;
	ptr->design = 2;
	palette_color(ptr);
	ptr->zoom = 1;
	ptr->j_cte = complex(-0.7, 0.27015);
	ptr->m_puis = 2;
	ptr->j_puis = 2;
	init_img(ptr);
}

t_complex	complex(double a, double b)
{
	t_complex	z;

	z.re = a;
	z.im = b;
	return (z);
}

float	mod(t_complex z)
{
	return (sqrt(pow(z.re, 2) + pow(z.im, 2)));
}
