#include "fractol.h"

void	julia(t_graphic ptr)
{
	t_complex	c;
	t_complex	z;
	t_complex	z1;
	int		k;
	int		i;
	int		j;

	i = 0;
	//c = complex(-0.7, 0.27015);
	c = complex(-0.9, 0.4);
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			z.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr.zoom;
			z.re = (j - WIDTH/2.0) * 4/WIDTH * ptr.zoom;
			k = -1;
			while (mod(z) <= 2 && ++k < ptr.max_iter)
			{
				z1.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
				z1.im = 2 * z.re * z.im + c.im;
				z = z1;
			}
			if (k < ptr.max_iter)
				img_put_pixel(&ptr, j, i, design_color(ptr, k));
			else
				img_put_pixel(&ptr, j, i, 0);
			j++;
		}
		i++;
	}
}
