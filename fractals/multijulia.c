/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/07 13:36:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*part_multijul(void *varg)
{
	t_fractol		*r;
	t_graphic	*ptr;
	t_complex	z[2];
	int			k;
	double		ind[2];

	r = (t_fractol*)varg;
	ptr = r->ptr;
	ind[0] = (HEIGHT * (r->p - 1) / DIV);
	while (ind[0] <= (HEIGHT / DIV) * r->p)
	{
		ind[1] = (WIDTH * (r->q - 1) / DIV);
		while (ind[1] <= ((WIDTH / DIV) * r->q))
		{
			z[0].im = ind[0] / ptr->zoom + (r->mouse).y;
			z[0].re = ind[1] / ptr->zoom + (r->mouse).x;
			k = -1;
			while (z[0].re * z[0].re + z[0].im * z[0].im < 4
					&& ++k < ptr->max_iter)
			{
				if (ptr->j_puis != 2)
				{
					z[1].re = pow(pow(z[0].re, 2) + pow(z[0].im, 2),
							ptr->j_puis / 2) * cos(ptr->j_puis * atan2(z[0].im,
									z[0].re)) + ptr->j_cte.re;
					z[1].im = pow(pow(z[0].re, 2) + pow(z[0].im, 2),
							ptr->j_puis / 2) * sin(ptr->j_puis * atan2(z[0].im,
									z[0].re)) + ptr->j_cte.im;
				}
				if (ptr->j_puis == 2)
				{
					z[1].re = pow(z[0].re, 2) - pow(z[0].im, 2) + ptr->j_cte.re;
					z[1].im = 2 * z[0].re * z[0].im + ptr->j_cte.im;
				}
				z[0] = z[1];
			}
			if (k < ptr->max_iter)
				img_put_pixel(ptr, ind[1], ind[0], design_color(*ptr, k));
			else
				img_put_pixel(ptr, ind[1], ind[0], intern_color(*ptr, k, z[0]));
			ind[1]++;
		}
		ind[0]++;
	}
	return (NULL);
}

void	multijulia(t_fractol *r)
{
	int			k;
	int			ind[2];
	t_fractol	*tmp;
	pthread_t	id_thread[DIV * DIV];

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
	k = -1;
	ind[0] = -1;
	while (++ind[0] < DIV * DIV)
		pthread_create(&id_thread[ind[0]], NULL, part_multijul,
				(void*)(&tmp[ind[0]]));
	while (++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	k = -1;
	free(tmp);
}
