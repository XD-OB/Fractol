/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:31:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/01/26 06:53:30 by obelouch         ###   ########.fr       */
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

struct			s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

#endif
