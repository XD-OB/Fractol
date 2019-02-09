/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 21:21:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static float	son(float s, int i, float l)
{
	if (l == -44)
		return (sin((s * s) / i) * 200);
	return (sin(s * i + l) * 127 + 128);
}

static int		map(int k)
{
	int		map[16];

	map[0] = rgb_map(0, 0, 26);
	map[1] = rgb_map(9, 1, 47);
	map[2] = rgb_map(0, 26, 102);
	map[3] = rgb_map(4, 4, 73);
	map[4] = rgb_map(0, 7, 100);
	map[5] = rgb_map(12, 44, 138);
	map[6] = rgb_map(24, 82, 177);
	map[7] = rgb_map(57, 125, 209);
	map[8] = rgb_map(134, 181, 229);
	map[9] = rgb_map(211, 236, 248);
	map[10] = rgb_map(241, 233, 191);
	map[11] = rgb_map(248, 201, 95);
	map[12] = rgb_map(255, 170, 0);
	map[13] = rgb_map(204, 128, 0);
	map[14] = rgb_map(255, 255, 0);
	map[15] = rgb_map(255, 152, 0);
	return (map[k % 16]);
}

static int		part_outer(t_graphic ptr, int k)
{
	if (ptr.design == 7)
		return (change_map(k));
	if (ptr.design == 8)
		return (change_map2(k));
	return (change_map3(k));
}

int				outer(t_graphic ptr, int k)
{
	if (ptr.design == 1)
		return (map(k));
	if (ptr.design == 2)
		return (rgb_map(k * 2, k * 10, k * 5));
	if (ptr.design == 3)
		return (rgb_map(son(0.4, k, 0), son(0.4, k, 2), son(0.4, k, 4)));
	if (ptr.design == 4)
		return (rgb_map(son(0.1, k, 0), son(0.2, k, 0), son(0.3, k, 0)));
	if (ptr.design == 5)
	{
		if (k % 64 * 64)
			return (rgb_map(k % 32, k % 64 * 64, k % 45 * 16));
		else
			return (rgb_map(k % 32, 0x00FF00, k % 45 * 16));
	}
	if (ptr.design == 6)
	{
		if ((k << 21) + (k << 10) + k * 8 != 0)
			return ((k << 21) + (k << 10) + k * 8);
		else
			return (0x330011);
	}
	if (ptr.design == 7 || ptr.design == 8 || ptr.design == 9)
		return (part_outer(ptr, k));
	return (0xFFFFFF);
}

int				inner(t_graphic ptr, int k, t_complex z)
{
	float	s;

	s = sqrt(mod2(z));
	if (ptr.intern == 1)
		return (rgb_map(k * 100 * sin(s), k * sin(s), 50 * k));
	if (ptr.intern == 2)
		return (rgb_map(s * 20, s * 5, s * 150));
	if (ptr.intern == 3)
		return (rgb_map(s * 300, 0, s * 450));
	if (ptr.intern == 4)
		return (rgb_map(son(s, 1, -44), son(s, 2, -44), son(s, 4, -44)));
	return (0);
}
