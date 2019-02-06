/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:09:22 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*part_julia(void *varg)
{
	t_fractol		*r;
	t_graphic	*ptr;
	t_complex	z;
	t_complex	z1;
	int		k;
	float		i;
	float		j;

	r = (t_fractol*)varg;
	ptr = r->ptr;
	i = (HEIGHT * (r->p - 1) / DIV);
	while (i <= (HEIGHT / DIV) * r->p)
	{
		j = (WIDTH * (r->q - 1) / DIV);
		while (j <= ((WIDTH / DIV) * r->q))
		{
			z.im = i / ptr->zoom + (r->mouse).y;
			z.re = j / ptr->zoom + (r->mouse).x;
			k = -1;
			while (z.re * z.re + z.im * z.im < 4 && ++k < ptr->max_iter)
			{
				if (ptr->j_puis != 2)
				{
					z1.re = pow(pow(z.re, 2) + pow(z.im, 2), ptr->j_puis / 2) * cos(ptr->j_puis * atan2(z.im, z.re)) + ptr->j_cte.re;
					z1.im = pow(pow(z.re, 2) + pow(z.im, 2), ptr->j_puis / 2) * sin(ptr->j_puis * atan2(z.im, z.re)) + ptr->j_cte.im;
				}
				if (ptr->j_puis == 2)
				{
					z1.re = pow(z.re, 2) - pow(z.im, 2) + ptr->j_cte.re;
					z1.im = 2 * z.re * z.im + ptr->j_cte.im;
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

void		julia(t_fractol *r)
{
	int		k;
	int		i;
	int		j;
	t_fractol		*tmp;
	pthread_t	id_thread[DIV * DIV];

	tmp = (t_fractol*)malloc(sizeof(t_fractol) * DIV * DIV);
	i = -1;
	while(++i < DIV * DIV)
		tmp[i] = *r;
	i = 0;
	while(++i <= DIV)
	{
		j = 0;
		while(++j <= DIV)
		{
			tmp[((i - 1) * DIV) + (j - 1)].p = i;
			tmp[((i - 1) * DIV) + (j - 1)].q = j;
		}
	}
	k = -1;
	i = -1;
	while(++i < DIV * DIV)
		pthread_create(&id_thread[i], NULL, part_julia, (void*)(&tmp[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	k = -1;
	free(tmp);
}
