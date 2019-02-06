/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:09:27 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:09:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*part_mandel(void *varg)
{
	t_ready		*r;
	t_graphic	*ptr;
	t_complex	c;
	t_complex	z;
	t_complex	z1;
	int	k;
	double	i;
	double	j;

	r = (t_ready*)varg;
	ptr = r->ptr;
	r->width = WIDTH;
	r->height = HEIGHT;
	i = (r->height * (r->p - 1)) / DIV;
	while (i < (r->height * r->p) / DIV)
	{
		c.im = i / ptr->zoom + (r->mouse).y;
		j = (r->width * (r->q - 1)) / DIV;
		while (j < (r->width * r->q) / DIV)
		{
			c.re = j / ptr->zoom + (r->mouse).x;
			z = complex(0, 0);
			k = -1;
			while (z.re * z.re + z.im * z.im < 4 && ++k < ptr->max_iter)
			{
				z1.re = z.re * z.re - z.im * z.im + c.re;
				z1.im = 2 * z.re * z.im + c.im;
				if (z1.re == z.re && z1.im == z.im)
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
void	mandelbrot(t_ready *r)
{
	int		k;
	int		i;
	int		j;
	t_ready		*tmp;
	pthread_t	id_thread[DIV * DIV];

	tmp = (t_ready*)malloc(sizeof(t_ready) * DIV * DIV);
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
		pthread_create(&id_thread[i], NULL, part_mandel, (void*)(&tmp[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	free(tmp);
}
