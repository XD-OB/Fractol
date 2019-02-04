/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:09 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:27:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			rgb_map(int r, int g, int b)
{
	return ((r << 16 & 0xFF0000) | (g << 8 & 0x00FF00) | (b & 0x0000FF));
}

static void	affect(double *color, double v1, double v2, double v3)
{
	color[0] = v1;
	color[1] = v2;
	color[2] = v3;
}

static int	set(int i)
{
	if ((i * 255) < 0)
		return (0);
	if (i > 1)
		return (255);
	return (i * 255);
}

static void	put_val(double *t, double *color, double *arg, double hf)
{
	t[0] = arg[1] * (1 - arg[0]);
	t[1] = arg[1] * (1 - arg[0] * ((hf / 60.0) - floor(hf / 60.0)));
	t[2] = arg[1] * (1 - arg[0] * (1 - ((hf / 60.0) - floor(hf / 60.0))));
	if (floor(hf / 60.0) == 0 || floor(hf / 60.0) == 6)
		affect(color, arg[1], t[2], t[0]);
	else if (floor(hf / 60.0) == 1)
		affect(color, t[1], arg[1], t[0]);
	else if (floor(hf / 60.0) == 2)
		affect(color, t[0], arg[1], t[2]);
	else if (floor(hf / 60.0) == 3)
		affect(color, t[0], t[1], arg[1]);
	else if (floor(hf / 60.0) == 4)
		affect(color, t[2], t[0], arg[1]);
	else if (floor(hf / 60.0) == 5 || floor(hf / 60.0) == -1)
		affect(color, arg[1], t[0], t[1]);
	else
		affect(color, arg[1], arg[1], arg[1]);
}

int			hsv(double h, double s, double v)
{
	double	hf;
	double	arg[2];
	double	tab[3];
	double	color[3];

	hf = h;
	arg[0] = s;
	arg[1] = v;
	while (hf < 0)
		hf += 360;
	while (hf >= 360)
		hf -= 360;
	if (v <= 0)
		affect(color, 0, 0, 0);
	else if (s <= 0)
		affect(color, v, v, v);
	else
		put_val(tab, color, arg, hf);
	affect(color, set((int)color[0]), set((int)color[1]), set((int)color[2]));
	return (rgb_map(color[0], color[1], color[2]));
}
