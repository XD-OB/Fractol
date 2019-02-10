/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:27 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/10 22:31:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		mfillz(t_graphic *ptr, int *ind, t_complex *z)
{
	z[1].re = z[0].re * z[0].re - z[0].im * z[0].im + z[2].re;
	z[1].im = 2 * z[0].re * z[0].im + z[2].im;
	if (z[1].re == z[0].re && z[1].im == z[0].im)
	{
		ind[2] = ptr->max_iter;
		return (1);
	}
	z[0] = z[1];
	return (0);
}

static void		*part_mandel(void *varg)
{
	t_fractol	*f;
	t_complex	z[3];
	int			ind[3];

	f = (t_fractol*)varg;
	ind[0] = ((HEIGHT * (f->div - 1)) / DIV) - 1;
	while (++ind[0] < (HEIGHT * f->div) / DIV)
	{
		z[2].im = ind[0] / f->ptr->zoom + (f->mouse).y;
		ind[1] = - 1;
		while (++ind[1] < WIDTH)
		{
			z[2].re = ind[1] / f->ptr->zoom + (f->mouse).x;
			z[0] = complex(0, 0);
			ind[2] = -1;
			while (mod2(z[0]) < 4 && ++ind[2] < f->ptr->max_iter)
				mfillz(f->ptr, ind, z);
			if (ind[2] < f->ptr->max_iter)
				img_put_pixel(f->ptr, ind[1], ind[0], outer(*(f->ptr), ind[2]));
			else
				img_put_pixel(f->ptr, ind[1], ind[0],
						inner(*(f->ptr), ind[2], z[0]));
		}
	}
	return (NULL);
}

void			mandelbrot(t_fractol *f)
{
	int			ind[2];
	t_fractol	*tmp;
	pthread_t	id[DIV];

	tmp = (t_fractol*)malloc(sizeof(t_fractol) * DIV);
	ind[0] = -1;
	while (++ind[0] < DIV)
	{
		tmp[ind[0]] = *f;
		tmp[ind[0]].div = ind[0] + 1;
	}
	ind[1] = -1;
	ind[0] = -1;
	while (++ind[0] < DIV)
		pthread_create(&id[ind[0]], NULL, part_mandel, (void*)(&tmp[ind[0]]));
	while (++ind[1] < DIV)
		pthread_join(id[ind[1]], NULL);
	free(tmp);
}
