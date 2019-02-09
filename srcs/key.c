/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 14:14:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		switch_color(t_graphic *ptr, int ext)
{
	if (ext == 1)
	{
		if (ptr->design != 9)
			ptr->design++;
		else
			ptr->design = 0;
	}
	else
	{
		if (ptr->intern == 4)
			ptr->intern = 0;
		else
			ptr->intern++;
	}
}

static void		julia_event(int kcode, t_graphic *ptr)
{
	if (kcode == K_K)
		ptr->j_puis++;
	else if (kcode == K_J)
		ptr->j_puis--;
	else if (kcode == K_Y)
		ptr->j_cte = complex(-0.8, 0.4);
	else if (kcode == K_U)
		ptr->j_cte = complex(-1.417022285618, 0.0099534);
	else if (kcode == K_I)
		ptr->j_cte = complex(-1.476, 0);
	else if (kcode == K_O)
		ptr->j_cte = complex(-0.038088, 0.9754633);
	else if (kcode == K_P)
		ptr->j_cte = complex(0.3, 0.5);
	else if (kcode == K_OPEN_ACO)
		ptr->j_cte = complex(-0.8, 0);
	else if (kcode == K_CLOSE_ACO)
		ptr->j_cte = complex(-0, 1);
}

static void		general_event(int kcode, t_fractol *f)
{
	if (kcode == K_ESC)
		exit(1);
	else if (kcode == K_X)
		switch_color(f->ptr, 0);
	else if (kcode == K_C)
		switch_color(f->ptr, 1);
	else if (kcode == K_PLUS)
		f->ptr->max_iter += 10;
	else if (kcode == K_MINUS
			&& f->ptr->max_iter > 10)
		f->ptr->max_iter -= 5;
	else if (kcode == K_P && f->type == INFCIRCLE)
	{
		if (f->ptr->design == 0)
			f->ptr->design = 1;
		else
			f->ptr->design = 0;
	}
	else if (kcode == K_SPACE)
	{
		init_mouse(&(f->mouse));
		init_ptr(f->ptr);
	}
	if (f->type == JULIA)
		julia_event(kcode, f->ptr);
}

int				key_event(int kcode, t_fractol *f)
{
	t_mouse		*mouse;

	general_event(kcode, f);
	mouse = &(f->mouse);
	if (kcode == K_1)
	{
		if(f->type != MULTIJULIA)
			f->type++;
		else
			f->type = JULIA;
	}
	else if (kcode == K_UP)
		mouse->y -= 30 / f->ptr->zoom;
	else if (kcode == K_DOWN)
		mouse->y += 30 / f->ptr->zoom;
	else if (kcode == K_LEFT)
		mouse->x -= 30 / f->ptr->zoom;
	else if (kcode == K_RIGHT)
		mouse->x += 30 / f->ptr->zoom;
	if (f->type != MANDELBROT && f->type != JULIA)
	{
		if (kcode == K_M)
			f->ptr->m_puis++;
		else if (kcode == K_N && f->ptr->m_puis >= 0)
			f->ptr->m_puis--;
	}
	fractal(f);
	return (1);
}

int				key_press(int kcode, t_fractol *r)
{
	t_mouse		*mouse;

	mouse = &(r->mouse);
	if (kcode == K_F)
	{
		if (mouse->isclick == 0)
			mouse->isclick = 1;
		else
			mouse->isclick = 0;
	}
	return (0);
}
