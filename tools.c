#include "fractol.h"

int	rgb_map(int r, int g, int b)
{
	return ((r<<16 & 0xFF0000) | (g<<8 & 0x00FF00) | (b & 0x0000FF));	
}
