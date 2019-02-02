#include "fractol.h"
static void		swap_pt(t_point *pt1, t_point *pt2)
{
		t_point	tmp;
		
		tmp = *pt1;
		*pt1 = *pt2;
		*pt2 = tmp;
}

static void		e_modif(double *e, t_point *delta, t_point *pt, int flag)
{
	if (flag == 1 || flag == -1)
	{
		*e += delta->x;
		pt->y += flag;
	}
	if (flag == 0)
	{
		*e += delta->y;
		pt->x++;
	}
}

static void		tracepdy(t_graphic *ptr, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = fabs(pf.y - pi.y);
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, 1);
			mlx_pixel_put(ptr->mlx, ptr->win, pi.x++, pi.y, color);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y < pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		mlx_pixel_put(ptr->mlx, ptr->win, pi.x, pi.y++, color);
	}
}

static void		tracemdy(t_graphic *ptr, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = fabs(pf.y - pi.y);
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, -1);
			mlx_pixel_put(ptr->mlx, ptr->win, pi.x++, pi.y, color);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y > pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		mlx_pixel_put(ptr->mlx, ptr->win, pi.x, pi.y--, color);
	}
}

void			traceline(t_graphic *ptr, t_point pi, t_point pf, int color)
{
	t_point		delta;
	double		e;

	if (pi.x > pf.x)
		swap_pt(&pi, &pf);
	delta.x = pf.x - pi.x;
	delta.y = pf.y - pi.y;
	mlx_pixel_put(ptr->mlx, ptr->win, pi.x, pi.y, color);
	if (delta.y > 0)
		tracepdy(ptr, pi, pf, color);
	else
		tracemdy(ptr, pi, pf, color);
	mlx_pixel_put(ptr->mlx, ptr->win, pf.x, pf.y, color);
}
