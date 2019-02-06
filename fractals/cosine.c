/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:08:46 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:08:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*part_cosine(void *varg)
{
	t_ready		*r;
	t_graphic	*ptr;
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
		c.im = i / ptr->zoom + (r->mouse).y;	
		j = (WIDTH * (r->q - 1)) / DIV;
		while (j < (WIDTH * r->q) / DIV)
		{
			c.re = j / ptr->zoom + (r->mouse).x;	
			z = complex(0, 0);
			k = -1;
			while (z.re * z.re + z.im * z.im < 4 && ++k < ptr->max_iter)
			{
				z1.re = cos(z.re) * cosh(z.im) + (c.re / (pow(c.re, 2) + pow(c.im, 2)));
				z1.im = -(sin(z.re) * sinh(z.im) + (c.im / (pow(c.re, 2) + pow(c.im, 2))));
				if (z1.re == z.re && z1.im == z.im)
				{
					k = ptr->max_iter;
					break;
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

void		cosine(t_ready *r)
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
		pthread_create(&id_thread[i], NULL, part_cosine, (void*)(&tmp[i]));
	while(++k < DIV * DIV)
		pthread_join(id_thread[k], NULL);
	free(tmp);
}
