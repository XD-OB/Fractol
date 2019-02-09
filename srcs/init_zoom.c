/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 14:08:02 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_ptr(t_graphic *ptr)
{
	ptr->max_iter = MAX_ITER;
	ptr->design = 0;
	ptr->intern = 0;
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

void	init_fractol(t_fractol *r, t_graphic *ptr)
{
	init_mouse(&(r->mouse));
	r->ptr = ptr;
	r->p = 0;
	r->q = 0;
}

void	ft_zoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x)
		- (x / ((r->ptr)->zoom * 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y)
		- (y / ((r->ptr)->zoom * 1.3));
	r->ptr->zoom *= 1.3;
	if (r->ptr->zoom < 1000)
		(r->ptr)->max_iter++;
	else
		(r->ptr)->max_iter += 50;
}

void	ft_unzoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x)
		- (x / ((r->ptr)->zoom / 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y)
		- (y / ((r->ptr)->zoom / 1.3));
	r->ptr->zoom /= 1.3;
	if (r->ptr->zoom < 1000)
		(r->ptr)->max_iter--;
	else
		(r->ptr)->max_iter -= 50;
}
