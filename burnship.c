#include "fractol.h"

void	*part_ship(void *varg)
{
	t_ready		*r;
	t_graphic	*ptr;
	t_complex	c;
	t_complex	z;
	t_complex	z1;
	int	k;
	int	i;
	int	j;

	r = (t_ready*)varg;
	ptr = r->ptr;
	i = (HEIGHT * (r->p - 1)) / DIV;
	while (i < (HEIGHT * r->p) / DIV)
	{
		c.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr->zoom;
		j = (WIDTH * (r->q - 1)) / DIV;
		while (j < (WIDTH * r->q) / DIV)
		{
			c.re = (j - WIDTH/2.0) * 4/WIDTH * ptr->zoom;	
			z = complex(0, 0);
			k = -1;
			while (mod(z) <= 2 && ++k < ptr->max_iter)
			{
				z1.re = pow(fabs(z.re), 2) - pow(fabs(z.im), 2) + c.re;
				z1.im = fabs(2 * z.re * z.im) + c.im;
				if (z1.re == z.re && z1.im == z.im)
				{
					k = ptr->max_iter;
					break;
				}
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
void	burnship(t_graphic *ptr)
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
		pthread_create(&id_thread[i], NULL, part_ship, (void*)(&r[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	free(r);
}
