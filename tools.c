#include "fractol.h"

int	rgb_map(int r, int g, int b)
{
	return ((r<<16 & 0xFF0000) | (g<<8 & 0x00FF00) | (b & 0x0000FF));	
}

int	design_color(t_graphic ptr, int k)
{
	if (ptr.design == 0 && ptr.palette != 0)
		return (ptr.map[k % 16]);
	if (ptr.palette == 0)
	{
		if (ptr.design == 1)
			return (rgb_map(k*2, k*10, k*5));
		if (ptr.design == 2)
			return (rgb_map(sin(0.3 * k) * 127 + 128, sin(0.3*k+2)*127+128, sin(0.3*k+4)*127+128));
		if (ptr.design == 3)
			return (rgb_map(sin(0.1 * k) * 127 + 128, sin(0.2*k)*127+128, sin(0.3*k)*127+128));
	}
	return (0);
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
