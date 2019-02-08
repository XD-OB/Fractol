/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:28:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/08 11:22:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x) - (x / ((r->ptr)->zoom * 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y) - (y / ((r->ptr)->zoom * 1.3));
	r->ptr->zoom *= 1.3;
	if (r->ptr->zoom < 1000)
		(r->ptr)->max_iter += 2;
	else
		(r->ptr)->max_iter += 20;
}

void	ft_unzoom(int x, int y, t_fractol *r)
{
	(&(r->mouse))->x = (x / (r->ptr)->zoom + (&(r->mouse))->x) - (x / ((r->ptr)->zoom / 1.3));
	(&(r->mouse))->y = (y / (r->ptr)->zoom + (&(r->mouse))->y) - (y / ((r->ptr)->zoom / 1.3));
	r->ptr->zoom /= 1.3;
	(r->ptr)->max_iter -= 10;
}
