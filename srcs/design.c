/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/07 15:14:22 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#define	SAN(n, p, l) (sin(n * p + l) * 127 + 128)

int	palette(int k)
{
	int	map[16];

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

int	outer(t_graphic ptr, int k)
{
	if (ptr.design == 1)
		return (palette(k));
	if (ptr.design == 2)
		return (rgb_map(k * 2, k * 10, k * 5));
	if (ptr.design == 3)
		return (rgb_map(SAN(0.4, k, 0), SAN(0.4, k, 2), SAN(0.4, k, 4)));
	if (ptr.design == 4)
		return (rgb_map(SAN(0.1, k, 0), SAN(0.2, k, 0), SAN(0.3, k, 0)));
	if (ptr.design == 5)
		return (rgb_map(k % 32, k % 64 * 64 ? k % 64 * 64 : 0x00FF00,
					k % 45 * 16));
	if (ptr.design == 6)
	{
		if ((k << 21) + (k << 10) + k * 8 != 0)
			return ((k << 21) + (k << 10) + k * 8);
		else
			return (0x330011);
	}
	if (ptr.design == 7)
		return (change_map(k));
	if (ptr.design == 8)
		return (change_map2(k));
	if (ptr.design == 9)
		return (change_map3(k));
	return (0xFFFFFF);
}

int	inner(t_graphic ptr, int k, t_complex z)
{
	if (ptr.intern == 1)
		return (hsv(255 * k / ptr.max_iter, 255,
					k <  ptr.max_iter ? k : 0.0));
	if (ptr.intern == 2)
		return (rgb_map(k * 100 * sin(sqrt(z.re * z.re + z.im * z.im)),
					k * sin(sqrt(z.re * z.re + z.im * z.im)), 50 * k));
	if (ptr.intern == 3)
		return (rgb_map(sqrt(z.re * z.re + z.im * z.im) * 20,
					sqrt(z.re * z.re + z.im * z.im) * 5,
					sqrt(z.re * z.re + z.im * z.im) * 150));
	if (ptr.intern == 4)
		return (rgb_map(sqrt(z.re * z.re + z.im * z.im) * 300, 0,
					sqrt(z.re * z.re + z.im * z.im) * 450));
	if (ptr.intern == 5)
		return (rgb_map(sin(z.re * z.re + z.im * z.im) * 200,
					sin((z.re * z.re + z.im * z.im) / 2) * 200,
					sin((z.re * z.re + z.im * z.im) / 4) * 200));
	return (0);
}
