/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/15 22:19:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_ptr(t_graphic *ptr)
{
	ptr->max_iter = MAX_ITER;
	ptr->design = 3;
	ptr->intern = 0;
	ptr->zoom = 200;
	ptr->j_cte = complex(-0.7, 0.27015);
	ptr->m_puis = 3;
	init_img(ptr);
}

void	init_mouse(t_mouse *mouse)
{
	mouse->x = -2.4;
	mouse->y = -1.5;
	mouse->isclick = 0;
}

void	init_fractol(t_fractol *f, t_graphic *ptr)
{
	init_mouse(&(f->mouse));
	f->ptr = ptr;
	f->type = NONE;
	f->div = 0;
}

void	ft_zoom(int x, int y, t_fractol *f)
{
	(&(f->mouse))->x = (x / (f->ptr)->zoom + (&(f->mouse))->x)
		- (x / ((f->ptr)->zoom * 1.3));
	(&(f->mouse))->y = (y / (f->ptr)->zoom + (&(f->mouse))->y)
		- (y / ((f->ptr)->zoom * 1.3));
	f->ptr->zoom *= 1.3;
	(f->ptr)->max_iter++;
}

void	ft_unzoom(int x, int y, t_fractol *f)
{
	(&(f->mouse))->x = (x / (f->ptr)->zoom + (&(f->mouse))->x)
		- (x / ((f->ptr)->zoom / 1.3));
	(&(f->mouse))->y = (y / (f->ptr)->zoom + (&(f->mouse))->y)
		- (y / ((f->ptr)->zoom / 1.3));
	f->ptr->zoom /= 1.3;
	if (f->ptr->max_iter > 5)
		(f->ptr)->max_iter--;
}
