/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallette1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:54:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/11 10:36:37 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fill_wiki2(int *map)
{
	map[31] = 0xF2E1A7;
	map[32] = 0xF4D98F;
	map[33] = 0xF6D177;
	map[34] = 0xF8CA5F;
	map[35] = 0xF9C247;
	map[36] = 0xFBBA2F;
	map[37] = 0xFDB217;
	map[38] = 0xFFAA00;
	map[39] = 0xF8A400;
	map[40] = 0xF29F00;
	map[41] = 0xEB9A00;
	map[42] = 0xE59500;
	map[43] = 0xDE9000;
	map[44] = 0xD88B00;
	map[45] = 0xD28600;
	map[46] = 0xCC8100;
	map[47] = 0xC57B00;
	map[48] = 0xBF7600;
	map[49] = 0xB26C00;
	map[50] = 0xA56100;
	map[51] = 0x995700;
	map[52] = 0x8D4E00;
	map[53] = 0x814501;
	map[54] = 0x753C02;
	map[55] = 0x6A3303;
}

static void		fill_wiki1(int *map)
{
	map[7] = 0x0C2B8A;
	map[8] = 0x0D2F8E;
	map[9] = 0x0F3493;
	map[10] = 0x103998;
	map[11] = 0x123E9D;
	map[12] = 0x1342A2;
	map[13] = 0x1547A7;
	map[14] = 0x1951B1;
	map[15] = 0x205CB9;
	map[16] = 0x2867C1;
	map[17] = 0x3072C9;
	map[18] = 0x387DD1;
	map[19] = 0x4B8BD6;
	map[20] = 0x5F99DB;
	map[21] = 0x72A7E0;
	map[22] = 0x86B5E5;
	map[23] = 0x99C2E9;
	map[24] = 0xADD0EE;
	map[25] = 0xC0DEF3;
	map[26] = 0xD4ECF8;
	map[27] = 0xDBEBE9;
	map[28] = 0xE2EADB;
	map[29] = 0xE9E9CD;
	map[30] = 0xF1E9BF;
}

int				wiki_map(int k)
{
	int		map[56];

	map[0] = 0x03106D;
	map[1] = 0x041370;
	map[2] = 0x051673;
	map[3] = 0x061977;
	map[4] = 0x071D7B;
	map[5] = 0x092280;
	map[6] = 0x0A2685;
	fill_wiki1(map);
	fill_wiki2(map);
	return (map[k % 56]);
}
