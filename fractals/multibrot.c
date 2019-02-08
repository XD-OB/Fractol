/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:43 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/08 12:36:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		mmfillz(t_graphic *ptr, int *k, t_complex *z)
{
	z[1].re = pow((pow(z[0].re, 2) + pow(z[0].im, 2)),
			(ptr->m_puis / 2.0)) * cos(ptr->m_puis
				* atan2(z[0].im, z[0].re)) + z[2].re;
	z[1].im = pow((pow(z[0].re, 2) + pow(z[0].im, 2)),
			(ptr->m_puis / 2.0)) * sin(ptr->m_puis
				* atan2(z[0].im, z[0].re)) + z[2].im;
	if (z[1].re == z[0].re && z[1].im == z[0].im)
	{
		*k = ptr->max_iter;
		return (1);
	}
	z[0] = z[1];
	return (0);
}

static void		*part_multi(void *varg)
{
	t_fractol	*r;
	t_complex	z[3];
	int			ind[3];

	r = (t_fractol*)varg;
	ind[0] = ((HEIGHT * (r->p - 1)) / DIV) - 1;
	while (++ind[0] < (HEIGHT * r->p) / DIV)
	{
		z[2].im = ind[0] / r->ptr->zoom + (r->mouse).y;
		ind[1] = ((WIDTH * (r->q - 1)) / DIV) - 1;
		while (++ind[1] < (WIDTH * r->q) / DIV)
		{
			z[2].re = ind[1] / r->ptr->zoom + (r->mouse).x;
			z[0] = complex(0, 0);
			ind[2] = -1;
			while (mod2(z[0]) < 4 && ++ind[2] < r->ptr->max_iter)
				mmfillz(r->ptr, &ind[2], z);
			if (ind[2] < r->ptr->max_iter)
				img_put_pixel(r->ptr, ind[1], ind[0], outer(*(r->ptr), ind[2]));
			else
				img_put_pixel(r->ptr, ind[1], ind[0],
						inner(*(r->ptr), ind[2], z[0]));
		}
	}
	return (NULL);
}

void			multibrot(t_fractol *r)
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
		pthread_create(&id[ind[0]], NULL, part_multi, (void*)(&tmp[ind[0]]));
	while (++ind[2] < DIV * DIV)
		pthread_join(id[ind[2]], NULL);
	free(tmp);
}
