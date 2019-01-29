#include "fractol.h"

void	mandelbrot(t_graphic ptr)
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
		c.im = (i - HEIGHT/2.0) * 4/WIDTH;
		j = 0;
		while (j < WIDTH)
		{
			c.re = (j - WIDTH/2.0) * 4/WIDTH;
			z = complex(0, 0);
			k = -1;
			while (mod(z) <= 2 && ++k < ptr.max_iter)
			{
				z1.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
				z1.im = 2 * z.re * z.im + c.im;
				z = z1;
			}
			if (k < ptr.max_iter)
			{
				if (ptr.design == 0 && ptr.palette != 0)
					mlx_pixel_put(ptr.mlx, ptr.win, j, i, ptr.map[k%16]);
				else if (ptr.palette == 0)
				{
					if (ptr.design == 1)
						mlx_pixel_put(ptr.mlx, ptr.win, j, i, rgb_map(k * 2, k * 10, k * 5));
					else if (ptr.design == 2)
						mlx_pixel_put(ptr.mlx, ptr.win, j, i, rgb_map(sin(0.3 * k) * 127 + 128, sin(0.3*k+2)*127+128, sin(0.3*k+4)*127+128));
					else if (ptr.design == 3)
						mlx_pixel_put(ptr.mlx, ptr.win, j, i, rgb_map(sin(0.1 * k) * 127 + 128, sin(0.2*k)*127+128, sin(0.3*k)*127+128));
				}
			}
			else
				mlx_pixel_put(ptr.mlx, ptr.win, j, i, 0);
			j++;
		}
		i++;
	}
}
