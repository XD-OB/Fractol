#include "fractol.h"

void	*part_feigen(void *varg)
{
	t_ready		*r;
	t_graphic	*ptr;
	t_complex	tmp;
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
		tmp.im = (i - HEIGHT/2.0) * 4/WIDTH * ptr->zoom;
		j = (WIDTH * (r->q - 1)) / DIV;
		while (j < (WIDTH * r->q) / DIV)
		{
			tmp.re = (j - WIDTH/2.0) * 4/WIDTH * ptr->zoom;
			c.re = pow(tmp.re, 3) - 3 * tmp.re * pow(tmp.im, 2);
			c.im = 3 * pow(tmp.re, 2) * tmp.im - pow(tmp.im, 3);
			z = complex(0, 0);
			k = -1;
			while (z.re * z.re + z.im * z.im < 4 && ++k < ptr->max_iter)
			{
				z1.re = pow((pow(z.re, 2) + pow(z.im, 2)), ((ptr->m_puis - 1) / 2.0)) * cos((ptr->m_puis - 1) * atan2(z.im, z.re)) + c.re -1.401155;
				z1.im = pow((pow(z.re, 2) + pow(z.im, 2)), ((ptr->m_puis - 1) / 2.0)) * sin((ptr->m_puis - 1) * atan2(z.im, z.re)) + c.im;
				if (z.re == z1.re && z.im == z1.im)
				{
					k = ptr->max_iter;
					break ;
				}
				z = z1;
			}
			if (k < ptr->max_iter)
				img_put_pixel(ptr, j, i, design_color(*ptr, k));
			else
				img_put_pixel(ptr, j, i, intern_color(*ptr, k, z));
			j++;
		}
		i++;
	}
	return (NULL);
}

void		feigenbaum(t_graphic *ptr)
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
		pthread_create(&id_thread[i], NULL, part_feigen, (void*)(&r[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	free(r);
}
