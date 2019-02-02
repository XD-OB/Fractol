#include "fractol.h"

void	*part_star(void *varg)
{
	t_ready		*r;
	t_graphic	*ptr;
	t_complex	z;
	t_complex	z1;
	int		k;
	float		i;
	float		j;

	r = (t_ready*)varg;
	ptr = r->ptr;
	i = (HEIGHT * (r->p - 1) / DIV);
	while (i <= (HEIGHT / DIV) * r->p)
	{
		j = (WIDTH * (r->q - 1) / DIV);
		while (j <= ((WIDTH / DIV) * r->q))
		{
			z.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr->zoom;
			z.re = (j - WIDTH/2.0) * 4/WIDTH * ptr->zoom;
			k = -1;
			while (mod(z) <= 2 && ++k < ptr->max_iter)
			{
				z1.re = pow(pow(z.re, 2) + pow(z.im, 2), 2.5) * cos(5 * atan2(z.im, z.re)) - 0.5;
				z1.im = pow(pow(z.re, 2) + pow(z.im, 2), 2.5) * sin(5 * atan2(z.im, z.re)) + 0.64;
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
	return (NULL);
}

void		star_julia(t_graphic *ptr)
{
	int		k;
	int		i;
	int		j;
	t_ready		*r;
	pthread_t	id_thread[DIV * DIV];

	r = (t_ready*)malloc(sizeof(t_ready) * DIV * DIV);
	i = -1;
	while(++i < DIV * DIV)
		init_ready(&r[i], ptr);
	i = 0;
	while(++i <= DIV)
	{
		j = 0;
		while(++j <= DIV)
		{
			r[((i - 1) * DIV) + (j - 1)].p = i;
			r[((i - 1) * DIV) + (j - 1)].q = j;
		}
	}
	k = -1;
	i = -1;
	while(++i < DIV * DIV)
		pthread_create(&id_thread[i], NULL, part_star, (void*)(&r[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	free(r);
}
