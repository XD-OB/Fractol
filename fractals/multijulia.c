/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/08 12:49:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mjfillz(t_graphic *ptr, t_complex *z)
{
	if (ptr->j_puis == 2)
	{
		z[1].re = z[0].re * z[0].re - z[0].im * z[0].im + ptr->j_cte.re;
		z[1].im = 2 * z[0].re * z[0].im + ptr->j_cte.im;
		z[0] = z[1];
	}
	else
	{
		z[1].re = pow(pow(z[0].re, 2) + pow(z[0].im, 2),
				ptr->j_puis / 2) * cos(ptr->j_puis * atan2(z[0].im,
						z[0].re)) + ptr->j_cte.re;
		z[1].im = pow(pow(z[0].re, 2) + pow(z[0].im, 2),
				ptr->j_puis / 2) * sin(ptr->j_puis * atan2(z[0].im,
						z[0].re)) + ptr->j_cte.im;
	}
}

static void		*part_multij(void *varg)
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
				mjfillz(r->ptr, z);
			if (k < r->ptr->max_iter)
				img_put_pixel(r->ptr, ind[1], ind[0], outer(*(r->ptr), k));
			else
				img_put_pixel(r->ptr, ind[1], ind[0], inner(*(r->ptr),
							k, z[0]));
		}
	}
	return (NULL);
}

void			multijulia(t_fractol *r)
{
	int			ind[3];
	t_fractol	*tmp;
	pthread_t	id[DIV * DIV];

	tmp = (t_fractol*)malloc(sizeof(t_fractol) * DIV * DIV);
	ind[0] = -1;
	while (++ind[0] < DIV * DIV)
		tmp[ind[0]] = *r;
	ind[0] = 0;
	while (++ind[0] <= DIV)
	{
		ind[1] = 0;
		while (++ind[1] <= DIV)
		{
			tmp[((ind[0] - 1) * DIV) + (ind[1] - 1)].p = ind[0];
			tmp[((ind[0] - 1) * DIV) + (ind[1] - 1)].q = ind[1];
		}
	}
	ind[2] = -1;
	ind[0] = -1;
	while (++ind[0] < DIV * DIV)
		pthread_create(&id[ind[0]], NULL, part_multij, (void*)(&tmp[ind[0]]));
	while (++ind[2] < DIV * DIV)
		pthread_join(id[ind[2]], NULL);
	free(tmp);
}
