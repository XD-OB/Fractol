/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 22:25:47 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_ptr(t_graphic *ptr)
{
	ptr->max_iter = MAX_ITER;
	ptr->design = 4;
	ptr->intern = 2;
	ptr->zoom = 200;
	ptr->j_cte = complex(-0.7, 0.27015);
	ptr->m_puis = 3;
	ptr->j_puis = 2;
	init_img(ptr);
}

void	init_mouse(t_mouse *mouse)
{
	mouse->x = -2.05;
	mouse->y = -1.3;
	mouse->isclick = 0;
}

void	init_fractol(t_fractol *f, t_graphic *ptr)
{
	init_mouse(&(f->mouse));
	f->ptr = ptr;
	f->type = NONE;
	f->p = 0;
	f->q = 0;
}

void	ft_zoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x)
		- (x / ((r->ptr)->zoom * 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y)
		- (y / ((r->ptr)->zoom * 1.3));
	r->ptr->zoom *= 1.3;
	(r->ptr)->max_iter += 2;
}

void	ft_unzoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x)
		- (x / ((r->ptr)->zoom / 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y)
		- (y / ((r->ptr)->zoom / 1.3));
	r->ptr->zoom /= 1.3;
	if (r->ptr->max_iter > 5)
		(r->ptr)->max_iter -= 2;
}
