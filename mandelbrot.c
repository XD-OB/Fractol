#include "fractol.h"

void	mandelbrot(t_graphic ptr)
{
	float	x_c;
	float	y_c;
	float	x;
	float	y;
	float	xn;
	float	yn;
	int	k;
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
			while (mod_z_2 <= 4 && k < ptr.max_iter)
			{
				xn = pow(x, 2) - pow(y, 2) + x_c;
				yn = 2 * x * y + y_c;
				x = xn;
				y = yn;
				mod_z_2 = pow(x, 2) + pow(y, 2);
				k++;
			}
			if (k < ptr.max_iter)
				mlx_pixel_put(ptr.mlx, ptr.win, j, i, ptr.map[k % 16].color);
			else
				mlx_pixel_put(ptr.mlx, ptr.win, j, i, 0);
			j++;
		}
		i++;
	}
}
