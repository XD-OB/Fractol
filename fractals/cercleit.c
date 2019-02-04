/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cercleit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 08:44:06 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:08:37 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_circle(t_point c, t_point p, t_graphic ptr)
{
	mlx_pixel_put(ptr.mlx, ptr.win, c.x + p.x, c.y + p.y, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x - p.x, c.y + p.y, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x + p.x, c.y - p.y, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x - p.x, c.y - p.y, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x + p.y, c.y + p.x, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x - p.y, c.y + p.x, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x + p.y, c.y - p.x, 0);
	mlx_pixel_put(ptr.mlx, ptr.win, c.x - p.y, c.y - p.x, 0);
}

void	circle(t_point c, int r, t_graphic ptr)
{
	int			d;
	t_point		p;

	p.x = 0;
	p.y = r;
	d = 3 - 2 * r;
	draw_circle(c, p, ptr);
	while (p.y >= p.x)
	{
		p.x++;
		if (d > 0)
		{
			p.y--;
			d += 4 * (p.x - p.y) + 10;
		}
		else
			d += 4 * p.x + 6;
		draw_circle(c, p, ptr);
	}
}

t_point	point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	whitescreen(t_graphic *ptr)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

void	infcircle(t_point c, int r, t_graphic ptr, int n)
{
	int		width;
	int		height;
	
	if (r > 8)
	{
		if (n == 2)
			r /= 2;
		infcircle(point(c.x + r / 2, c.y), n * r / 2, ptr, n);
		infcircle(point(c.x - r / 2, c.y), n * r / 2, ptr, n);
		infcircle(point(c.x, c.y + r / 2), n * r / 2, ptr, n);
		infcircle(point(c.x, c.y - r / 2), n * r / 2, ptr, n);
	}
	circle(c, r, ptr);
}
