/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/07 15:12:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	switch_design(t_graphic *ptr)
{
	if (ptr->design != 9)
		ptr->design++;
	else
		ptr->design = 0;
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
	if (keycode == K_K)
		ptr->j_puis++;
	else if (keycode == K_J)
		ptr->j_puis--;
	else if (keycode == K_Y)
		ptr->j_cte = complex(-0.8, 0.4);
	else if (keycode == K_U)
		ptr->j_cte = complex(-1.417022285618, 0.0099534);
	else if (keycode == K_I)
		ptr->j_cte = complex(-1.476, 0);
	else if (keycode == K_O)
		ptr->j_cte = complex(-0.038088, 0.9754633);
	else if (keycode == K_P)
		ptr->j_cte = complex(0.3, 0.5);
	else if (keycode == K_OPEN_ACO)
		ptr->j_cte = complex(-0.8, 0);
	else if (keycode == K_CLOSE_ACO)
		ptr->j_cte = complex(-0, 1);
}

static void		brot_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_M)
		ptr->m_puis++;
	else if (keycode == K_N && ptr->m_puis >= 0)
		ptr->m_puis--;
}

int			mouse_event(int mousecode, int x, int y, t_fractol *r)
{
	
	if (mousecode == SCROLL_UP || mousecode == B_LEFT)
		ft_zoom(x, y, r);
	if (mousecode == SCROLL_DOWN || mousecode == B_RIGHT)
		ft_unzoom(x, y, r);
	fractal(r);
	return (1);
}

int			mouse_move(int x, int y, t_fractol *r)
{
	t_complex	*c;

	c = &(r->ptr->j_cte);
	if (r->type == JULIA && x > 0 && y > 0 && y < HEIGHT && x < WIDTH && r->mouse.isclick == 1)
	{
		c->re = (float)WIDTH / 1200 - (float)x / 1000; 
		c->im = (float)HEIGHT / 1200 - (float)y / 1000;
	}
		fractal(r);
	return (1);
}

int			win_close(t_fractol *r)
{
	(void)r;
	exit(0);
	return (0);
}

int			key_press(int keycode, t_fractol *r)
{
	t_mouse		*mouse;

	mouse = &(r->mouse);
	if (keycode == K_F)
	{
		if (mouse->isclick == 0)
			mouse->isclick = 1;
		else
			mouse->isclick = 0;
	}
	return (0);
}

int			key_event(int keycode, t_fractol *r)
{
	t_mouse		*mouse;

	mouse = &(r->mouse);
	if (keycode == K_ESC)
		exit(1);
	else if (keycode == K_X)
		switch_intern(r->ptr);
	else if (keycode == K_C)
		switch_design(r->ptr);
	else if (keycode == K_PLUS)
		r->ptr->max_iter += 10;
	else if (keycode == K_MINUS && r->ptr->max_iter > 10)
		r->ptr->max_iter -= 5;
	else if (keycode == K_P && r->type == INFCIRCLE)
	{
		if (r->ptr->design == 0)
			r->ptr->design = 1;
		else
			r->ptr->design = 0;
	}
	else if (keycode == K_UP)
		mouse->y -= 30 / r->ptr->zoom;
	else if (keycode == K_DOWN)
		mouse->y += 30 / r->ptr->zoom;
	else if (keycode == K_LEFT)
		mouse->x -= 30 / r->ptr->zoom;
	else if (keycode == K_RIGHT)
		mouse->x += 30 / r->ptr->zoom;
	if (r->type == JULIA)
		julia_event(keycode, r->ptr);
	if (r->type != MANDELBROT && r->type != JULIA)
		brot_event(keycode, r->ptr);
	if (keycode == K_SPACE)
	{
		init_mouse(&(r->mouse));
		init_ptr(r->ptr);
	}
	fractal(r);
	return (1);
}
