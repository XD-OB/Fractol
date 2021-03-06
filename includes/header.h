/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:54:06 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/15 22:10:48 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define P(x, y) sqrt(pow(x - 1 / 4, 2) + pow(y, 2))
# define WIDTH 1200
# define HEIGHT 800
# define MAX_ITER 50
# define DIV 20
# define JULIA_C 0.001
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define B_RIGHT 2
# define B_LEFT 1
# define K_MINUS 78
# define K_PLUS 69
# define K_SPACE 49
# define K_C 8
# define K_F 3
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
# define K_OPEN_ACO 33
# define K_CLOSE_ACO 30

enum
{
	JULIA,
	STAR,
	LOOP,
	MANDELBROT,
	MULTIBROT,
	TRICORN,
	DOUADY,
	FEIGENBAUM,
	COSINE,
	BURNSHIP,
	INFCIRCLE,
	LEAF,
	SJULIA,
	GALAXY,
	INTERN,
	CANTOR,
	NONE
};

#endif
