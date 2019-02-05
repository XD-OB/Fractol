/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:31:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:10:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define	FRACTOL_H

# include "header.h"
# include "structs.h"

void		init_mouse(t_mouse *mouse);
int		mouse_event(int mcode, int x, int y, t_ready *r);
void		ft_zoom(int x, int y, t_ready *r);
void		ft_unzoom(int x, int y, t_ready *r);
float		lerp(float v0, float v1, float t);
void			whitescreen(t_graphic *ptr);
t_point			point(int x, int y);
void			infcircle(t_point p, int r, t_graphic ptr, int n);
void		change_map(t_graphic *ptr);
void		palette_color(t_graphic *ptr);
int			hsv(double h, double s, double v);
int			design_color(t_graphic ptr, int k);
int			intern_color(t_graphic ptr, int k, t_complex z);
int			rgb_map(int r, int g, int b);
void		error(void);
void		fractal(t_graphic *ptr, t_ready *r);
void		tricorn(t_graphic *ptr);
void		mandelbrot(t_ready *r);
void		multibrot(t_graphic *ptr);
void		burnship(t_graphic *ptr);
void		feigenbaum(t_graphic *ptr);
void		cosine(t_graphic *ptr);
void		star(t_graphic *ptr);
void		julia(t_graphic *ptr);
void		init_ready(t_ready *r, t_graphic *ptr);
void		init_ptr(t_graphic *ptr);
t_complex	complex(double a, double b);
void		init_img(t_graphic *ptr);
void		img_put_pixel(t_graphic *ptr, double x, double y, int color);
void		img_clear(t_graphic *ptr);
int			key_event(int keycode, t_ready *r);


#endif
