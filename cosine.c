#include "fractol.h"

static void	part_cosine(t_graphic ptr, int p, int q)
{
	t_complex	c;
	t_complex	z;
	t_complex	z1;
	int	k;
	int	i;
	int	j;

	i = (HEIGHT * (p - 1)) / DIV;
	while (i < (HEIGHT * p) / DIV)
	{
		c.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr.zoom;
		j = (WIDTH * (q - 1)) / DIV;
		while (j < (WIDTH * q) / DIV)
		{
			c.re = (j - WIDTH/2.0) * 4/WIDTH * ptr.zoom;	
			z = complex(0, 0);
			k = -1;
			while (mod(z) <= 2 && ++k < ptr.max_iter)
			{
				z1.re = cos(z.re) * cosh(z.im) + (c.re / (pow(c.re, 2) + pow(c.im, 2)));
				z1.im = -(sin(z.re) * sinh(z.im) + (c.im / (pow(c.re, 2) + pow(c.im, 2))));
				z = z1;
			}
			if (k < ptr.max_iter)
				img_put_pixel(&ptr, j, i, design_color(ptr, k));
			else
				img_put_pixel(&ptr, j, i, intern_color(ptr, k, mod(z)));
			j++;
		}
		i++;
	}
}

void		cosine(t_graphic ptr)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= DIV)
	{
		j = 0;
		while (++j <= DIV)
			part_cosine(ptr, i, j);
	}
}

