/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:12:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/09 22:04:46 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int ac, char **av)
{
	t_graphic	ptr;
	t_fractol	f;

	f.ptr = &ptr;
	if (ac != 2)
		error();
	init_ptr(f.ptr);
	init_fractol(&f, f.ptr);
	fractal_type(&f, av[1]);
	menu(f);
	(f.ptr)->mlx = mlx_init();
	(f.ptr)->win = mlx_new_window((f.ptr)->mlx, WIDTH, HEIGHT,
		"Fract'ol obelouch");
	fractal(&f);
	mlx_key_hook((f.ptr)->win, key_event, &f);
	mlx_mouse_hook((f.ptr)->win, mouse_event, &f);
	mlx_hook((f.ptr)->win, 6, 1L << 6, mouse_move, &f);
	mlx_hook((f.ptr)->win, 17, 1L << 17, win_close, &f);
	mlx_hook((f.ptr)->win, 2, 1L << 2, key_press, &f);
	mlx_loop((f.ptr)->mlx);
	return (0);
}
