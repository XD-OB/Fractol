#include "../includes/fractol.h"

void	ft_zoom(int x, int y, t_ready *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x) - (x / ((r->ptr)->zoom * 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y) - (y / ((r->ptr)->zoom * 1.3));
	r->ptr->zoom *= 1.3;
	if (r->ptr->zoom < 2000)
		(r->ptr)->max_iter += 20;
	else
		(r->ptr)->max_iter += 100;
}

void	ft_unzoom(int x, int y, t_ready *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x) - (x / ((r->ptr)->zoom / 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y) - (y / ((r->ptr)->zoom / 1.3));
	r->ptr->zoom /= 1.3;
	(r->ptr)->max_iter -= 10;
}
