#include "fractol.h"

void	*hello(void *vargp)
{
	char	*myid = (char*)vargp;
	ft_putstr(myid);
	return NULL;
}

void	*part_julia(t_graphic *ptr, int p, int q)
{
	t_complex	z;
	t_complex	z1;
	int		k;
	float		i;
	float		j;

	i = (HEIGHT * (p - 1)) / NBR_THREAD;
	while (i < (HEIGHT * p) / NBR_THREAD)
	{
		j = (WIDTH * (q - 1)) / NBR_THREAD;
		while (j < (WIDTH * q) / NBR_THREAD)
		{
			z.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr->zoom;
			z.re = (j - WIDTH/2.0) * 4/WIDTH * ptr->zoom;
			k = -1;
			while (mod(z) <= 2 && ++k < ptr->max_iter)
			{
				z1.re = pow(pow(z.re, 2) + pow(z.im, 2), ptr->j_puis / 2) * cos(ptr->j_puis * atan2(z.im, z.re)) + ptr->j_cte.re;
				z1.im = pow(pow(z.re, 2) + pow(z.im, 2), ptr->j_puis / 2) * sin(ptr->j_puis * atan2(z.im, z.re)) + ptr->j_cte.im;
				z = z1;
			}
			if (k < ptr->max_iter)
				img_put_pixel(ptr, j, i, design_color(*ptr, k));
			else
				img_put_pixel(ptr, j, i, intern_color(*ptr, k, mod(z)));
			j++;
		}
		i++;
	}
	return NULL;
}

void		julia(t_graphic *ptr)
{
	int		i;
	int		j;
	pthread_t	tid;
	t_ready		*r;
	char		*str = "hi\n";

	i = 0;
	while (++i <= NBR_THREAD)
	{
		j = 0;
		while (++j <= NBR_THREAD)
			//pthread_create(&tid, NULL, hello, (void*)str);
			part_julia(ptr, i, j);
	}
	//pthread_exit(NULL);
}
