#include "fractol.h"

static void	switch_design(t_graphic *ptr)
{
	if (ptr->design != 0 && ptr->design != 3)
		ptr->design++;
	else if (ptr->design == 0)
	{
		ptr->design = 1;
		ptr->palette = 0;
	}
	else if (ptr->design == 3)
	{
		ptr->design = 0;
		ptr->palette = 1;
	}
}

static void	switch_intern(t_graphic *ptr)
{
	if (ptr->intern == 5)
		ptr->intern = 0;
	else
		ptr->intern++;
}

static void		julia_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_K && ptr->type == JULIA)
		ptr->j_puis++;
	else if (keycode == K_J && ptr->type == JULIA)
		ptr->j_puis--;
	else if (keycode == K_7 && ptr->type == JULIA)
		ptr->j_cte.re += JULIA_C;
	else if (keycode == K_8 && ptr->type == JULIA)
		ptr->j_cte.im += JULIA_C;
	else if (keycode == K_4 && ptr->type == JULIA)
		ptr->j_cte.re -= JULIA_C;
	else if (keycode == K_5 && ptr->type == JULIA)
		ptr->j_cte.im -= JULIA_C;
	else if (keycode == K_Y && ptr->type == JULIA)
		ptr->j_cte = complex(0.285, 0.01);
	else if (keycode == K_U && ptr->type == JULIA)
		ptr->j_cte = complex(-1.417022285618, 0.0099534);
	else if (keycode == K_I && ptr->type == JULIA)
		ptr->j_cte = complex(-1.476, 0);
	else if (keycode == K_O && ptr->type == JULIA)
		ptr->j_cte = complex(-0.038088, 0.9754633);
	else if (keycode == K_P && ptr->type == JULIA)
		ptr->j_cte = complex(-0.4, 0.6);
	else if (keycode == K_ACOLADE && ptr->type == JULIA)
		ptr->j_cte = complex(-0.8, 0.156);
	else if (keycode == K_ACOLADE && ptr->type == JULIA)
		ptr->j_cte = complex(-0, 1);
}

static void		mandel_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_M && ptr->type == MANDELBROT)
		ptr->m_puis++;
	else if (keycode == K_N && ptr->m_puis >= 0 && ptr->type == MANDELBROT)
		ptr->m_puis--;
}

int			key_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_ESC)
		exit(1);
	else if (keycode == K_X)
		switch_intern(ptr);
	else if (keycode == K_C)
		switch_design(ptr);
	else if (keycode == K_PLUS)
		ptr->max_iter += 10;
	else if (keycode == K_MINUS && ptr->max_iter > 10)
		ptr->max_iter -= 5;
	else if (keycode == K_2)
		ptr->zoom -= 0.05;
	else if (keycode == K_1)
		ptr->zoom += 0.05;
	julia_event(keycode, ptr);
	mandel_event(keycode, ptr);
	if (keycode == K_SPACE)
		init_ptr(ptr);
	//mlx_clear_window(ptr->mlx, ptr->win);
	img_clear(ptr);
	fractal(ptr);
	return (1);
}
