/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:31:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/15 22:10:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "header.h"
# include "structs.h"

void		fractal_type(t_fractol *f, char *str);
void		menu(t_fractol f);
int			win_close(t_fractol *r);
void		init_mouse(t_mouse *mouse);
int			mouse_event(int mcode, int x, int y, t_fractol *r);
int			mouse_move(int x, int y, t_fractol *r);
int			key_press(int kcode, t_fractol *r);
void		ft_zoom(int x, int y, t_fractol *r);
void		ft_unzoom(int x, int y, t_fractol *r);
float		lerp(float v0, float v1, float t);
float		mod2(t_complex c);
int			wiki_map(int k);
void		whitescreen(t_graphic *ptr);
t_point		point(int x, int y);
void		infcircle(t_point p, int r, t_graphic ptr, int n);
int			hsv(double h, double s, double v);
int			outer(t_graphic ptr, int k);
int			inner(t_graphic ptr, int k, t_complex z);
int			rgb_map(int r, int g, int b);
void		error(void);
void		fractal(t_fractol *r);
void		tricorn(t_fractol *r);
void		mandelbrot(t_fractol *r);
void		multibrot(t_fractol *r);
void		burnship(t_fractol *r);
void		feigenbaum(t_fractol *r);
void		cosine(t_fractol *r);
void		star(t_graphic *ptr);
void		julia(t_fractol *r);
void		init_fractol(t_fractol *r, t_graphic *ptr);
void		init_ptr(t_graphic *ptr);
t_complex	complex(double a, double b);
void		init_img(t_graphic *ptr);
void		img_put_pixel(t_graphic *ptr, double x, double y, int color);
void		img_clear(t_graphic *ptr);
int			key_event(int keycode, t_fractol *r);

#endif
