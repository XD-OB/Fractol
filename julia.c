#include "fractol.h"

void	*hello(void *vargp)
{
	char	*myid = (char*)vargp;
	ft_putstr(myid);
	return NULL;
}

void	*part_julia(void *varg)
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
	printf("r->p  %d\nr->q  %d\n", r->p, r->q);
	i = (HEIGHT * (r->p - 1) / NBR_THREAD);
	while (i <= (HEIGHT / NBR_THREAD) * r->p)
	{
		j = (WIDTH * (r->q - 1) / NBR_THREAD);
		while (j <= ((WIDTH / NBR_THREAD) * r->q))
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
	return (NULL);
}

void		julia(t_graphic *ptr)
{
	int		i;
	int		j;
	pthread_t	tid[NBR_THREAD * NBR_THREAD];
	pthread_t	ti;
	t_ready		r;

	init_ready(&r, ptr);
	r.p = 0;
	while (++r.p <= NBR_THREAD)
	{
		r.q = 0;
		while (++r.q <= NBR_THREAD)
		{
			pthread_create(&tid[(r.p - 1) * (r.q -  1) + (r.q + 1)], NULL, part_julia, (void*)&r);
			pthread_join(tid[(r.p - 1) * (r.q -  1) + (r.q + 1)], NULL);
		}
	}
	i = -1;
	while (++i < NBR_THREAD * NBR_THREAD)
		pthread_join(tid[i], NULL);
/* 
	init_ready(&r, ptr);
	i = 0; 
	r.p = 1;
	r.q = 1;
	printf("r.p  %d\nr.q  %d\n", r.p, r.q);
	pthread_create(&tid[i], NULL, part_julia, (void*)&r);
	pthread_join(tid[i], NULL);
	i = 1;
	r.p = 1;
	r.q = 2;
	pthread_create(&tid[i], NULL, part_julia, (void*)&r);
	pthread_join(tid[i], NULL);
	i = 2; 
	r.p = 1;
	r.q = 3;
	pthread_create(&tid[i], NULL, part_julia, (void*)&r);
	pthread_join(tid[i], NULL);
*/
}
