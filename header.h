#ifndef HEADER_H
#define HEADER_H

#include <pthread.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIDTH 900
# define HEIGHT 600

# define P(x, y) sqrt(pow(x - 1 / 4, 2) + pow(y, 2))

# define MAX_ITER 50
# define DIV 4
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
# define K_OPEN_ACO 33
# define K_CLOSE_ACO 30

enum
{
	JULIA,
	MANDELBROT,
	DOUADY,
	FEIGENBAUM,
	COSINE,
	BURNSHIP,
	NONE
};

#endif
