#include "../includes/fractol.h"

static void	fill_map(int *design)
{
	design[20] = 0x00FF7F;
	design[21] = 0x00EF9F;
	design[22] = 0x00DFBF;
	design[23] = 0x00CFDF;
	design[24] = 0x00BFFF;
	design[25] = 0x00AFFF;
	design[26] = 0x009FFF;
	design[27] = 0x008FFF;
	design[28] = 0x007FFF;
	design[29] = 0x006FFF;
	design[30] = 0x005FFF;
	design[31] = 0x004FFF;
	design[32] = 0x003FFF;
	design[33] = 0x002FFF;
	design[34] = 0x001FFF;
	design[35] = 0X0000FF;
	design[36] = 0x1F00FF;
	design[37] = 0x3F00FF;
	design[38] = 0x5F00FF;
	design[39] = 0x7F00FF;
	design[40] = 0x9F00DF;
	design[41] = 0xBF00BF;
	design[42] = 0xDF009F;
	design[43] = 0xFF007F;
}

static void	fill_map2(int *design)
{
	design[44] = 0xFF005F;
	design[45] = 0xFF003F;
	design[46] = 0xFF001F;
	design[47] = 0xFF0000;
	design[48] = 0xFF0F00;
	design[49] = 0xFF1F00;
	design[50] = 0xFF2F00;
	design[51] = 0xFF3F00;
	design[52] = 0xFF4F00;
	design[53] = 0xFF5F00;
	design[54] = 0xFF6F00;
	design[55] = 0xFF7F00;
	design[56] = 0xFF8F00;
	design[57] = 0xFF9F00;
	design[58] = 0xFFA700;
	design[59] = 0xFFAF00;
	design[60] = 0xFFB700;
	design[61] = 0xFFBF00;
	design[62] = 0xFFCF00;
	design[63] = 0xFFDF00;
	design[64] = 0xFFFF00;
}

int		change_map(int k)
{
	int	design[65];

	design[0] = 0x33CCCC;
	design[1] = 0x28C1AD;
	design[2] = 0x1EB78E;
	design[3] = 0x14AD70;
	design[4] = 0x0AA351;
	design[5] = 0x009933;
	design[6] = 0x00A228;
	design[7] = 0x00AB1E;
	design[8] = 0x00B514;
	design[9] = 0x00BE0A;
	design[10] = 0x00C800;
	design[11] = 0x26D300;
	design[12] = 0x4CDE00;
	design[13] = 0x72E900;
	design[14] = 0x98F400;
	design[15] = 0xBFFF00;
	design[16] = 0xBFFF00;
	design[17] = 0x8FFF1F;
	design[18] = 0x5FFF3F;
	design[19] = 0x2FFF5F;
	fill_map(design);
	return (design[k % 65]);
}
