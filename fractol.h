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

# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123

# define K_MINUS 78
# define K_PLUS 69
# define K_SPACE 49
# define K_C 8

enum
{
	JULIA,
	MANDELBROT
};

typedef struct		s_complex
{
	float		re;
	float		im;
}			t_complex;

typedef struct		s_graphic
{
	void*		mlx;
	void*		win;
	int		max_iter;
	int		map[16];
	int		palette;
	int		design;
	int		type;
}			t_graphic;

void		fractal(t_graphic ptr);
void		mandelbrot(t_graphic ptr);
void		julia(t_graphic ptr);
int		rgb_map(int r, int g, int b);
void		init_ptr(t_graphic *ptr);
int		ft_tabsize(int map[16]);
t_complex	complex(float a, float b);
float		mod(t_complex z);
int		key_event(int keycode, t_graphic *ptr);

typedef struct		s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

#endif
