#include "fractol.h"

int	rgb_map(int r, int g, int b)
{
	return ((r<<16 & 0xFF0000) | (g<<8 & 0x00FF00) | (b & 0x0000FF));	
}

t_complex	complex(float a, float b)
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
