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

# define P(x, y) sqrt(pow(x - 1 / 4, 2) + pow(y, 2))

# define MAX_ITER 3000
# define DIV 100
# define JULIA_C 0.0005

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
# define K_J 38
# define K_K 40
# define K_X 7
# define K_1 83
# define K_2 84
# define K_4 21
# define K_5 23
# define K_7 89
# define K_8 91
# define K_ACOLADE 33

enum
{
	JULIA,
	MANDELBROT,
	DOUADY,
	FEIGENBAUM,
	COSINE,
	NONE
};

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
int			design_color(t_graphic ptr, int k);
int			intern_color(t_graphic ptr, int k, double m_z);
int			rgb_map(int r, int g, int b);
void		error(void);
void		fractal(t_graphic *ptr);
void		mandelbrot(t_graphic ptr);
void		feigenbaum(t_graphic ptr);
void		cosine(t_graphic ptr);
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
