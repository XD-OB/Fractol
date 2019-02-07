/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/07 16:05:04 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		jfillz(t_graphic *ptr, t_complex *z)
{
	z[1].re = z[0].re * z[0].re - z[0].im * z[0].im + ptr->j_cte.re;
	z[1].im = 2 * z[0].re * z[0].im + ptr->j_cte.im;
	z[0] = z[1];
}

static void		*part_j(void *varg)
{
	t_fractol	*r;
	t_complex	z[2];
	int			k;
	double		ind[2];

	r = (t_fractol*)varg;
	ind[0] = (HEIGHT * (r->p - 1) / DIV) - 1;
	while (++ind[0] <= (HEIGHT / DIV) * r->p)
	{
		ind[1] = (WIDTH * (r->q - 1) / DIV) - 1;
		while (++ind[1] <= ((WIDTH / DIV) * r->q))
		{
			z[0].im = ind[0] / r->ptr->zoom + (r->mouse).y;
			z[0].re = ind[1] / r->ptr->zoom + (r->mouse).x;
			k = -1;
			while (mod2(z[0]) < 4 && ++k < r->ptr->max_iter)
				jfillz(r->ptr, z);
			if (k < r->ptr->max_iter)
				img_put_pixel(r->ptr, ind[1], ind[0], outer(*(r->ptr), k));
			else
				img_put_pixel(r->ptr, ind[1], ind[0], inner(*(r->ptr),
							k, z[0]));
		}
	}
	return (NULL);
}

static void		fullpq(t_fractol *fract)
{
	int		i;
	int		j;

	i = 0;
	while (++i <= DIV)
	{
		j = 0;
		while (++j <= DIV)
		{
			fract[((i - 1) * DIV) + (j - 1)].p = i;
			fract[((i - 1) * DIV) + (j - 1)].q = j;
		}
	}
}

void			julia(t_fractol *r)
{
	int			i;
	int			k;
	t_fractol	*tmp;
	pthread_t	id[DIV * DIV];

	tmp = (t_fractol*)malloc(sizeof(t_fractol) * DIV * DIV);
	i = -1;
	while (++i < DIV * DIV)
		tmp[i] = *r;
	fullpq(tmp);
	k = -1;
	i = -1;
	while (++i < DIV * DIV)
		pthread_create(&id[i], NULL, part_j, (void*)(&tmp[i]));
	while (++k < DIV * DIV)
		pthread_join(id[k], NULL);
	free(tmp);
}
