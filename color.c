#include "fractol.h"

int		rgb_map(int r, int g, int b)
{
	return ((r<<16 & 0xFF0000) | (g<<8 & 0x00FF00) | (b & 0x0000FF));
}

static void	affect(double *color, double v1, double v2, double v3)
{
	color[0] = v1;
	color[1] = v2;
	color[2] = v3;
}

static int	set(int i)
{
	if ((i * 255) < 0)
		return (0);
	if (i > 1)
		return (255);
	return (i * 255);
}

static void	put_val(double *t, double s, double v, double H)
{
	t[0] = v * (1 - s);
	t[1] = v * (1 - s * ((H / 60.0) - floor(H / 60.0)));
	t[2] = v * (1 - s * (1 - ((H / 60.0) - floor(H / 60.0))));
}

int		hsv(double h, double s, double v)
{
	double	H;
	double	tab[3];
	double	color[3];

	H = h;
	while (H < 0)
		H += 360;
	while (H >= 360)
		H -= 360;
	if (v <= 0)
		affect(color, 0, 0, 0);
	else if (s <= 0)
		affect(color, v, v, v);
	else
	{
		put_val(tab, s, v, H);
		if (floor(H / 60.0) == 0)
			affect(color, v, tab[2], tab[0]);
		else if (floor(H / 60.0) == 1)
			affect(color, tab[1], v, tab[0]);
		else if (floor(H / 60.0) == 2)
			affect(color, tab[0], v, tab[2]);
		else if (floor(H / 60.0) == 3)
			affect(color, tab[0], tab[1], v);
		else if (floor(H / 60.0) == 4)
			affect(color, tab[2], tab[0], v);
		else if (floor(H / 60.0) == 5)
			affect(color, v, tab[0], tab[1]);
		else if (floor(H / 60.0) == 6)
			affect(color, v, tab[2], tab[0]);
		else if (floor(H / 60.0) == -1)
			affect(color, v, tab[0], tab[1]);
		else
			affect(color, v, v, v);
	}
	affect(color, set((int)color[0]), set((int)color[1]), set((int)color[2]));
	return (rgb_map(color[0], color[1], color[2]));
}
