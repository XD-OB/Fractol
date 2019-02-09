/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:17:13 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 14:23:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			change_map(int k)
{
	int		design[16];

	design[0] = 0x33CCCC;
	design[1] = 0x009933;
	design[2] = 0x00C800;
	design[3] = 0xBFFF00;
	design[4] = 0x00FF7F;
	design[5] = 0x00BFFF;
	design[6] = 0x007FFF;
	design[7] = 0x0000FF;
	design[8] = 0x7F00FF;
	design[9] = 0xFF007F;
	design[10] = 0xFF0000;
	design[11] = 0xFF3F00;
	design[12] = 0xFF7F00;
	design[13] = 0xFFBF00;
	design[14] = 0xFFB3E6;
	design[15] = 0xFFFF00;
	return (design[k % 16]);
}

int			change_map2(int k)
{
	int		design[16];

	design[0] = 0x00FF00;
	design[1] = 0x10DA50;
	design[2] = 0x200210;
	design[3] = 0x301488;
	design[4] = 0x405922;
	design[5] = 0x50ADAD;
	design[6] = 0x60AD90;
	design[7] = 0x70BBCC;
	design[8] = 0x80DABC;
	design[9] = 0x902121;
	design[10] = 0xA032A3;
	design[11] = 0xB0AB12;
	design[12] = 0xC08243;
	design[13] = 0xD06555;
	design[14] = 0xE01341;
	design[15] = 0xF0FFFF;
	return (design[k % 16]);
}

static void	changeit1(int *design)
{
	design[21] = 0x005454;
	design[22] = 0x005858;
	design[23] = 0x005C5C;
	design[24] = 0x006060;
	design[25] = 0x006464;
	design[26] = 0x006868;
	design[27] = 0x006C6C;
	design[28] = 0x007070;
	design[29] = 0x007474;
	design[30] = 0x007878;
	design[31] = 0x007C7C;
	design[32] = 0x008080;
	design[33] = 0x008484;
	design[34] = 0x008888;
	design[35] = 0x008C8C;
	design[36] = 0x009090;
	design[37] = 0x009494;
	design[38] = 0x009898;
	design[39] = 0x009C9C;
	design[40] = 0x00A0A0;
}

int			change_map3(int k)
{
	int		design[65];

	design[0] = 0x0;
	design[1] = 0x000404;
	design[2] = 0x000808;
	design[3] = 0x000C0C;
	design[4] = 0x001010;
	design[5] = 0x001414;
	design[6] = 0x001818;
	design[7] = 0x001C1C;
	design[8] = 0x002020;
	design[9] = 0x002424;
	design[10] = 0x002828;
	design[11] = 0x002C2C;
	design[12] = 0x003030;
	design[13] = 0x003434;
	design[14] = 0x003838;
	design[15] = 0x003C3C;
	design[16] = 0x004040;
	design[17] = 0x004444;
	design[18] = 0x004848;
	design[19] = 0x004C4C;
	design[20] = 0x005050;
	changeit1(design);
	design[41] = 0x00A4A4;
	design[42] = 0x00A8A8;
	design[43] = 0x00ACAC;
	design[44] = 0x00B0B0;
	design[45] = 0x00B4B4;
	design[46] = 0x00B8B8;
	design[47] = 0x00BCBC;
	design[48] = 0x00C0C0;
	design[49] = 0x00C4C4;
	design[50] = 0x00C8C8;
	design[51] = 0x00CCCC;
	design[52] = 0x00D0D0;
	design[53] = 0x00D4D4;
	design[54] = 0x00D8D8;
	design[55] = 0x00DCDC;
	design[56] = 0x00E0E0;
	design[57] = 0x00E4E4;
	design[58] = 0x00E8E8;
	design[59] = 0x00ECEC;
	design[60] = 0x00F0F0;
	design[61] = 0x00F4F4;
	design[62] = 0x00F8F8;
	design[63] = 0x00FCFC;
	design[64] = 0x00FFFF;
	return (design[k % 65]);
}
