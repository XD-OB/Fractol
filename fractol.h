/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:31:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/01/30 22:44:07 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define	FRACTOL_H

# include "header.h"

typedef struct	s_complex
{
	float		re;
	float		im;
}				t_complex;

typedef struct	s_image
{
	void		*void_ptr;
	char		*img;
	int			bpp;
	int			s_l;
	int			endian;
}				t_image;

typedef struct	s_graphic
{
	void*		mlx;
	void*		win;
	int			max_iter;
	int			map[16];
	int			design;
	int			intern;
	int			type;
	float		zoom;
	t_image		image;
	t_complex	j_cte;
	float		j_puis;
	float		m_puis;
}				t_graphic;

typedef struct	s_ready
{
	t_graphic	*ptr;
	int		p;
	int		q;
}		t_ready;

void		palette_color(t_graphic *ptr);
int		hsv(double h, double s, double v);
int			design_color(t_graphic ptr, int k);
int			intern_color(t_graphic ptr, int k, double m_z);
int			rgb_map(int r, int g, int b);
void		error(void);
void		fractal(t_graphic *ptr);
void		mandelbrot(t_graphic *ptr);
void		burnship(t_graphic *ptr);
void		feigenbaum(t_graphic *ptr);
void		cosine(t_graphic *ptr);
void		julia(t_graphic *ptr);
void		init_ready(t_ready *r, t_graphic *ptr);
void		init_ptr(t_graphic *ptr);
t_complex	complex(double a, double b);
float		mod(t_complex z);
void		init_img(t_graphic *ptr);
void		img_put_pixel(t_graphic *ptr, double x, double y, int color);
void		img_clear(t_graphic *ptr);
int			key_event(int keycode, t_graphic *ptr);


#endif
