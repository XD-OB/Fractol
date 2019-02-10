/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallette2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:58:05 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/10 23:58:07 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fillmap21(int *design)
{
	design[21] = 0x5CAD95;
	design[22] = 0x60AD90;
	design[23] = 0x63AF9C;
	design[24] = 0x66B2A8;
	design[25] = 0x69B5B4;
	design[26] = 0x6CB8C0;
	design[27] = 0x70BBCC;
	design[28] = 0x73C1C8;
	design[29] = 0x76C7C5;
	design[30] = 0x79CDC2;
	design[31] = 0x80DABC;
	design[32] = 0x84AB95;
	design[33] = 0x887D6E;
	design[34] = 0x8C4F47;
	design[35] = 0x902121;
	design[36] = 0x942541;
	design[37] = 0x982962;
	design[38] = 0x9C2D82;
	design[39] = 0xA032A3;
	design[40] = 0xA4507E;
	design[41] = 0xA86E5A;
	design[42] = 0xAC8C36;
	design[43] = 0xB0AB12;
	design[44] = 0xB4A01E;
}

static void	fillmap22(int *design)
{
	design[45] = 0xB8962A;
	design[46] = 0xBC8C36;
	design[47] = 0xC08243;
	design[48] = 0xC47A47;
	design[49] = 0xC8734C;
	design[50] = 0xCC6C50;
	design[51] = 0xD06555;
	design[52] = 0xD45050;
	design[53] = 0xD83C4B;
	design[54] = 0xDC2746;
	design[55] = 0xE01341;
	design[56] = 0xE01341;
	design[57] = 0xE44E70;
	design[58] = 0xE889A0;
	design[59] = 0xECC4CF;
	design[60] = 0xEDD7DF;
	design[61] = 0xEEEBEF;
	design[62] = 0xF0FFFF;
}

int		change_map(int k)
{
	int	design[63];

	design[0] = 0x0CE140;
	design[1] = 0x10DA50;
	design[2] = 0x13AE43;
	design[3] = 0x168336;
	design[4] = 0x195829;
	design[5] = 0x1C2D1C;
	design[6] = 0x210210;
	design[7] = 0x230528;
	design[8] = 0x250730;
	design[9] = 0x260940;
	design[10] = 0x290C58;
	design[11] = 0x2C1070;
	design[12] = 0x301488;
	design[13] = 0x36328F;
	design[14] = 0x3C5196;
	design[15] = 0x436F9E;
	design[16] = 0x498EA5;
	design[17] = 0x50ADAD;
	design[18] = 0x53ADA7;
	design[19] = 0x56ADA1;
	design[20] = 0x59AD9B;
	fillmap21(design);
	fillmap22(design);
	return (design[k % 63]);	
}
