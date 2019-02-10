/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:17:13 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 22:48:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	changeit1(int *design)
{
	design[10] = 0xF35D3A;
	design[11] = 0xF3613A;
	design[12] = 0xF36539;
	design[13] = 0xF46939;
	design[14] = 0xF46D39;
	design[15] = 0xF47139;
	design[16] = 0xF47538;
	design[17] = 0xF57A38;
	design[18] = 0xF57E38;
	design[19] = 0xF58238;
	design[20] = 0xF68637;
	design[21] = 0xF68A37;
	design[22] = 0xF68E37;
	design[23] = 0xF79337;
	design[24] = 0xF79736;
	design[25] = 0xF79B36;
	design[26] = 0xF79F36;
	design[27] = 0xF8A336;
	design[28] = 0xF8A735;
	design[29] = 0xFBAB35;
	design[30] = 0xF9B035;
}

static void	changeit2(int *design)
{
	design[31] = 0xF9B435;
	design[32] = 0xF9B835;
	design[33] = 0xFABC34;
	design[34] = 0xFAC034;
	design[35] = 0xFAC434;
	design[36] = 0xFBC934;
	design[37] = 0xFBCD33;
	design[38] = 0xFBD133;
	design[39] = 0xFBD533;
	design[40] = 0xFCD933;
	design[41] = 0xFCDD32;
	design[42] = 0xFCE132;
	design[43] = 0xFDE632;
	design[44] = 0xFDEA32;
	design[45] = 0xFDEE31;
	design[46] = 0xFEF231;
	design[47] = 0xFEF631;
	design[48] = 0xFEFA31;
	design[49] = 0xFFFF31;
}

int			change_map4(int k)
{
	int		design[50];

	design[0] = 0xF0333C;
	design[1] = 0xF0373C;
	design[2] = 0xF03B3C;
	design[3] = 0xF03F3B;
	design[4] = 0xF1443B;
	design[5] = 0xF1483B;
	design[6] = 0xF14C3B;
	design[7] = 0xF2503A;
	design[8] = 0xF2543A;
	design[9] = 0xF2583A;
	changeit1(design);
	changeit2(design);
	return (design[k % 50]);
}
