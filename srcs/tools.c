/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:28:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 14:14:41 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	complex(double a, double b)
{
	t_complex	z;

	z.re = a;
	z.im = b;
	return (z);
}

float		mod2(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

t_point		point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
