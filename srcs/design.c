/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 23:23:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static float	son(float s, int i, float l)
{
	if (l == -44)
		return (sin((s * s) / i) * 200);
	return (sin(s * i + l) * 127 + 128);
}

int		wiki_map(int k)
{
	int		map[44];

//	map[0] = 0x421E0F;
//	map[1] = 0x3A1911;
//	map[2] = 0x321413;
//	map[3] = 0x2A1015;
//	map[4] = 0x220B17;
//	map[5] = 0x1A071A;
//	map[6] = 0x16051E;
//	map[7] = 0x130422;
//	map[8] = 0x0F0326;
//	map[9] = 0x0C022A;
//	map[10] = 0x09012F;
//	map[11] = 0x080134;
//	map[12] = 0x070239;
//	map[13] = 0x06023E;
//	map[14] = 0x050343;
//	map[15] = 0x040449;
//	map[16] = 0x03044F;
//	map[17] = 0x020556;
//	map[18] = 0x01065D;
//	map[19] = 0x000764;
	map[0] = 0x03106D;
	map[1] = 0x061977;
	map[2] = 0x092280;
	map[3] = 0x0C2B8A;
	map[4] = 0x0F3493;	
	map[5] = 0x123E9D;
	map[6] = 0x1547A7;
	map[7] = 0x1951B1;
	map[8] = 0x205CB9;
	map[9] = 0x2867C1;
	map[10] = 0x3072C9;
	map[11] = 0x387DD1;
	map[12] = 0x4B8BD6;
	map[13] = 0x5F99DB;
	map[14] = 0x72A7E0;
	map[15] = 0x86B5E5;	
	map[16] = 0x99C2E9;	
	map[17] = 0xADD0EE;
	map[18] = 0xC0DEF3;
	map[19] = 0xD4ECF8;
	map[20] = 0xDBEBE9;
	map[21] = 0xE2EADB;
	map[22] = 0xE9E9CD;
	map[23] = 0xF1E9BF;
	map[24] = 0xF2E1A7;
	map[25] = 0xF4D98F;
	map[26] = 0xF6D177;
	map[27] = 0xF8CA5F;
	map[28] = 0xF9C247;
	map[29] = 0xFBBA2F;
	map[30] = 0xFDB217;
	map[31] = 0xFFAA00;
	map[32] = 0xF29F00;
	map[33] = 0xE59500;
	map[34] = 0xD88B00;
	map[35] = 0xCC8100;
	map[36] = 0xBF7600;	
	map[37] = 0xB26C00;
	map[38] = 0xA56100;	
	map[39] = 0x995700;
	map[40] = 0x8D4E00;
	map[41] = 0x814501;
	map[42] = 0x753C02;
	map[43] = 0x6A3303;
	return (map[k % 44]);
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
		return (wiki_map(k));
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
