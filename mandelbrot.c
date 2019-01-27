#include "fractol.h"

void	mandelbrot(t_graphic ptr)
{
	float	x_c;
	float	y_c;
	float	x;
	float	y;
	float	xn;
	float	yn;
	float	k;
	float	mod_z_2;
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		y_c = (i - HEIGHT/2.0) * 4/WIDTH;
		j = 0;
		while (j < WIDTH)
		{
			x_c = (j - WIDTH/2.0) * 4/WIDTH;
			x = 0;
			y = 0;
			k = 0;
			mod_z_2 = 0;
			while (mod_z_2 <= 4 && k < 15)
			{
				xn = pow(x, 2) - pow(y, 2) + x_c;
				yn = 2 * x * y + y_c;
				x = xn;
				y = yn;
				mod_z_2 = pow(x, 2) + pow(y, 2);
				k++;
			}
			if (k < MAX_ITER)
				mlx_pixel_put(ptr.mlx, ptr.win, j, i, rgb_map(k * 20 + 50 > 255 ? 255 : k * 20 + 50, 0, 0));
			else
				mlx_pixel_put(ptr.mlx, ptr.win, j, i, 0);
			j++;
		}
		i++;
	}
}
