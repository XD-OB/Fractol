/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:08:27 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/08 12:29:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		bfillz(t_graphic *ptr, int *ind, t_complex *z)
{
	z[1].re = fabs(z[0].re * z[0].re) -
		fabs(z[0].im * z[0].im) + z[2].re;
	z[1].im = fabs(2 * z[0].re * z[0].im) + z[2].im;
	if (z[1].re == z[0].re && z[1].im == z[0].im)
	{
		ind[2] = ptr->max_iter;
		return (1);
	}
	z[0] = z[1];
	return (0);
}

static void		*part_ship(void *varg)
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
				bfillz(r->ptr, ind, z);
			if (ind[2] < r->ptr->max_iter)
				img_put_pixel(r->ptr, ind[1], ind[0], outer(*(r->ptr), ind[2]));
			else
				img_put_pixel(r->ptr, ind[1], ind[0],
						inner(*(r->ptr), ind[2], z[0]));
		}
	}
	return (NULL);
}

void			burnship(t_fractol *r)
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
		pthread_create(&id[ind[0]], NULL, part_ship, (void*)(&tmp[ind[0]]));
	while (++ind[2] < DIV * DIV)
		pthread_join(id[ind[2]], NULL);
	free(tmp);
}
