/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:31:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/01/27 23:38:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define	FRACTOL_H

# include <pthread.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 500

# define JULIA_C 0.0005

# define P(x, y) sqrt(pow(x - 1 / 4, 2) + pow(y, 2))

# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123

# define K_MINUS 78
# define K_PLUS 69
# define K_SPACE 49
# define K_C 8
# define K_M 46
# define K_N 45
# define K_Y 16
# define K_U 32
# define K_I 34
# define K_O 31
# define K_P 35
# define K_1 83
# define K_2 84
# define K_7 89
# define K_8 91

enum
{
	JULIA,
	MANDELBROT,
	DOUADY,
	DENDRITE,
	FEIGENBAUM
};

typedef struct		s_complex
{
	float		re;
	float		im;
}			t_complex;

typedef struct		s_image
{
	void		*void_ptr;
	char		*img;
	int		bpp;
	int		s_l;
	int		endian;
}			t_image;

typedef struct		s_graphic
{
	void*		mlx;
	void*		win;
	int		max_iter;
	int		map[16];
	int		palette;
	int		design;
	int		type;
	float		zoom;
	t_image		image;
	t_complex	j_cte;
	float		m_puis;
}			t_graphic;

void		palette_color(t_graphic *ptr);
int		design_color(t_graphic ptr, int k);
void		fractal(t_graphic *ptr);
void		mandelbrot(t_graphic ptr);
void		feigenbaum(t_graphic ptr);
void		julia(t_graphic ptr);
int		rgb_map(int r, int g, int b);
void		init_ptr(t_graphic *ptr);
int		ft_tabsize(int map[16]);
t_complex	complex(double a, double b);
float		mod(t_complex z);
void		init_img(t_graphic *ptr);
void		img_put_pixel(t_graphic *ptr, double x, double y, int color);
void		img_clear(t_graphic *ptr);
int		key_event(int keycode, t_graphic *ptr);

typedef struct		s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

#endif
