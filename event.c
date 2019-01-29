#include "fractol.h"

static void	switch_design(t_graphic *ptr)
{
	if (ptr->design == 0)
	{
		ptr->design = 1;
		ptr->palette = 0;
	}
	else if (ptr->design == 3)
	{
		ptr->design = 0;
		ptr->palette = 1;
	}
	else
		ptr->design++;
}

int	key_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_ESC)
		exit(1);
	else if (keycode == K_C)
		switch_design(ptr);
	else if (keycode == K_PLUS)
		ptr->max_iter += 10;
	else if (keycode == K_MINUS)
		ptr->max_iter -= 10;
	else if (keycode == K_SPACE)
		init_ptr(ptr);
	mlx_clear_window(ptr->mlx, ptr->win);
	fractal(*ptr);	
	return (1);
}
