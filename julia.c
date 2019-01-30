#include "fractol.h"

void	julia(t_graphic ptr)
{
	t_complex	z;
	t_complex	z1;
	int		k;
	int		i;
	int		j;

	i = 0;
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
				z1.re = pow(pow(z.re, 2) + pow(z.im, 2), ptr.j_puis / 2) * cos(ptr.j_puis * atan2(z.im, z.re)) + ptr.j_cte.re;
				z1.im = pow(pow(z.re, 2) + pow(z.im, 2), ptr.j_puis / 2) * sin(ptr.j_puis * atan2(z.im, z.re)) + ptr.j_cte.im;
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
