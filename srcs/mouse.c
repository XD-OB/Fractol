/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:15:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 14:17:04 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_event(int mcode, int x, int y, t_fractol *f)
{
	if (mcode == SCROLL_UP || mcode == B_LEFT)
		ft_zoom(x, y, f);
	if (mcode == SCROLL_DOWN || mcode == B_RIGHT)
		ft_unzoom(x, y, f);
	fractal(f);
	return (1);
}

int		mouse_move(int x, int y, t_fractol *f)
{
	t_complex	*c;

	c = &(f->ptr->j_cte);
	if (f->type == JULIA && x > 0 && y > 0
			&& y < HEIGHT && x < WIDTH
			&& f->mouse.isclick == 1)
	{
		c->re = (float)WIDTH / 1200 - (float)x / 1000;
		c->im = (float)HEIGHT / 1200 - (float)y / 1000;
	}
	fractal(f);
	return (1);
}

int		win_close(t_fractol *f)
{
	(void)f;
	exit(0);
	return (0);
}
