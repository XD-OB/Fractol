/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/11 10:44:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static float	son(float s, int i, float l)
{
	if (l == -44)
		return (sin((s * s) / i) * 200);
	return (sin(s * i + l) * 127 + 128);
}

static int		part_outer(int n, int k)
{
	if (n == 9)
		return (rgb_map(son(0.3, k / 4, 1), son(0.1, k, 0), son(0.1, k, 2)));
	if (n == 10)
		return (rgb_map(son(0.1, k, 6), son(0.1, k, 7), son(0.1, k, 8)));
	if (n == 11)
		return (rgb_map(son(0.1, k, 0), son(0.1, k, 4), son(0.1, k, 8)));
	if (n == 12)
		return (rgb_map(son(0.1, k, 0), son(0.1, k, 2), son(0.1, k, 4)));
	if (n == 13)
		return (rgb_map(son(0.1, k, 3), son(0.1, k, 2), son(0.1, k, 1)));
	return (rgb_map(son(0.1, k, 0), son(0.05, k, 0), son(0.01, k, 0)));
}

int				outer(t_graphic ptr, int k)
{
	if (ptr.design == 1)
		return (wiki_map(k));
	if (ptr.design == 2)
		return (rgb_map(k, k * 5, k * 3));
	if (ptr.design == 3)
		return (rgb_map(son(0.1, k, 8), son(0.1, k, 0), son(0.1, k, 0)));
	if (ptr.design == 4)
		return (rgb_map(son(0.1, k, 0), son(0.15, k, 0), son(0.2, k, 0)));
	if (ptr.design == 5)
		return (rgb_map(son(0.1, k, 2), son(0.1, k, 4), son(0.1, k, 3)));
	if (ptr.design == 6)
		return (rgb_map(son(0.1, k, 1), son(0.1, k, 0), son(0.1, k, 1)));
	if (ptr.design == 7)
		return (rgb_map(son(0.1, k, 4), son(0.4, k, 0), son(0.1, k, 4)));
	if (ptr.design == 8)
		return (rgb_map(son(0.2, k, 6), son(0.1, k, 6), son(0.1, k, 8)));
	if (ptr.design > 8)
		return (part_outer(ptr.design, k));
	return (rgb_map(son(0.1, k, 1), son(0.1, k, 1), son(0.1, k, 1)));
}

int				inner(t_graphic ptr, int k, t_complex z)
{
	float	s;

	s = sqrt(mod2(z));
	if (ptr.intern == 1)
		return (rgb_map(son(0.1, k, 2), son(0.1, k, 2), son(0.1, k, 2)));
	if (ptr.intern == 2)
		return (rgb_map(s * 20, s * 5, s * 150));
	if (ptr.intern == 3)
		return (rgb_map(son(0.1, k, 0), son(0.1, k, 2), son(0.1, k, 4)));
	if (ptr.intern == 4)
		return (rgb_map(son(s, 1, -4), son(s, 2, -4), son(s, 4, -4)));
	if (ptr.intern == 5)
		return (rgb_map(son(k, k, k),
					son(k / 4, k / 2, k), son(k / 8, k / 4, k)));
	else
		return (0);
}
