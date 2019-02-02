#include "fractol.h"
#define	SAN(n, p, l) (sin(n * p + l) * 127 + 128)

void	palette_color(t_graphic *ptr)
{
	ptr->map[0] = rgb_map(66, 30, 15);
	ptr->map[1] = rgb_map(25, 7, 26);
	ptr->map[2] = rgb_map(9, 1, 47);
	ptr->map[3] = rgb_map(4, 4, 73);
	ptr->map[4] = rgb_map(0, 7, 100);
	ptr->map[5] = rgb_map(12, 44, 138);
	ptr->map[6] = rgb_map(24, 82, 177);
	ptr->map[7] = rgb_map(57, 125, 209);
	ptr->map[8] = rgb_map(134, 181, 229);
	ptr->map[9] = rgb_map(211, 236, 248);
	ptr->map[10] = rgb_map(241, 233, 191);
	ptr->map[11] = rgb_map(248, 201, 95);
	ptr->map[12] = rgb_map(255, 170, 0);
	ptr->map[13] = rgb_map(204, 128, 0);
	ptr->map[14] = rgb_map(153, 87, 0);
	ptr->map[15] = rgb_map(106, 52, 3);
}

int	design_color(t_graphic ptr, int k)
{
	if (ptr.design == 1)
		return (ptr.map[k % 16]);
	if (ptr.design == 2)
		return (rgb_map(k*2, k*10, k*5));
	if (ptr.design == 3)
		return (rgb_map(SAN(0.3, k, 0), SAN(0.3, k, 2), SAN(0.3, k, 4)));
	if (ptr.design == 4)
		return (rgb_map(SAN(0.1, k, 0), SAN(0.2, k, 0), SAN(0.3, k, 0)));
	if (ptr.design == 5)
		return (hsv((int)(k / ptr.max_iter), 255, k < ptr.max_iter ? 255 : 0));
	return (0xFFFFFF);
}

int	intern_color(t_graphic ptr, int k, double m_z)
{
	if (ptr.intern == 1)
		return (hsv(190, k / ptr.max_iter, 0.24));
	if (ptr.intern == 2)
		return (rgb_map(k * 100 * sin(m_z), k * sin(m_z), 50 * k));
	if (ptr.intern == 3)
		return (rgb_map(m_z * 20, m_z * 5, m_z * 150));
	if (ptr.intern == 4)
		return (rgb_map(m_z * 300, 0, m_z * 450));
	if (ptr.intern == 5)
		return (rgb_map(sin(m_z) * 200, sin(m_z / 2) * 200, sin(m_z / 4) * 200));
	return (0);
}
