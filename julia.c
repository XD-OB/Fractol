#include "fractol.h"

void	julia(t_graphic ptr)
{
	float	re_c;
	float	im_c;
	float	x;
	float	y;
	float	xn;
	float	yn;
	int	k;
	float	mod_z_2;
	int	i;
	int	j;

	re_c = -0.7;
	im_c = 0.27015;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			y = (i - HEIGHT/2.0) * 4/WIDTH;
			x = (j - WIDTH/2.0) * 4/WIDTH;
			k = 0;
			mod_z_2 = 0;
			while (mod_z_2 <= 4 && k < ptr.max_iter)
			{
				xn = pow(x, 2) - pow(y, 2) + re_c;
				yn = 2 * x * y + im_c;
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
