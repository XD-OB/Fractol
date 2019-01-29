#include "fractol.h"

void	init_img(t_graphic *ptr)
{
	t_image	*tmp;

	tmp = &ptr->image;
	tmp->void_ptr = mlx_new_image(ptr->mlx, WIDTH, HEIGHT);
	tmp->img = mlx_get_data_addr(tmp->void_ptr, &tmp->bpp, &tmp->s_l, &tmp->endian);
}

void	img_put_pixel(t_graphic *ptr, double x, double y, int color)
{
	t_image	*tmp;

	tmp = &(ptr->image);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int*)(tmp->img + (int)((y * WIDTH + x) * (tmp->bpp / 8))) = color;
}

void	img_clear(t_graphic *ptr)
{
	t_image	*tmp;

	tmp = &(ptr->image);
	ft_bzero(tmp->img, WIDTH * HEIGHT * (tmp->bpp / 8));
}
