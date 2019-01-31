#include "fractol.h"

void	cosine(t_graphic ptr)
{
	t_complex	c;
	t_complex	z;
	t_complex	z1;
	int	k;
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		c.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr.zoom;
		j = 0;
		while (j < WIDTH)
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
				img_put_pixel(&ptr, j, i, 0);
			j++;
		}
		i++;
	}
}
