/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:22:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/10 22:51:10 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			error(void)
{
	ft_putstr("\033[31mUsage: ./fractol  type\n\n");
	ft_putstr("\033[1;35mAvailable fractals:  \033[1;32m* Julia\n");
	ft_putstr("                     \033[1;32m* LoopJulia\n");
	ft_putstr("                     \033[1;32m* StarJulia\n");
	ft_putstr("                     \033[1;32m* CantorJulia\n");
	ft_putstr("                     \033[1;32m* Mandelbrot\n");
	ft_putstr("                     \033[1;32m* Multibrot\n");
	ft_putstr("                     \033[1;32m* Tricorn\n");
	ft_putstr("                     \033[1;32m* Douady\n");
	ft_putstr("                     \033[1;32m* Feigenbaum\n");
	ft_putstr("                     \033[1;32m* Cosine\n");
	ft_putstr("                     \033[1;32m* BurningShip\n");
	ft_putstr("                     \033[1;32m* SJulia\n");
	ft_putstr("                     \033[1;32m* Galaxy\n");
	ft_putstr("                     \033[1;32m* LeafJulia\n\033[0m");
	exit(-1);
}

static void		menu_julia(void)
{
	ft_putstr("\033[36m\n   ######### \033[1;32mMADE BY ");
	ft_putstr("OBELOUCH \033[0;36m########\n");
	ft_putstr("\033[0;36m   -----------------------------------\n");
	ft_putstr("   | ESC         :\033[1;34m   Close           \033[0;36m|\n");
	ft_putstr("   | SPACE       :\033[1;34m  Initialize       \033[0;36m|\n");
	ft_putstr("   | F           :\033[1;34m Lock/Free Motion  \033[0;36m|\n");
	ft_putstr("   | Arrows      :\033[1;34m  Move             \033[0;36m|\n");
	ft_putstr("   | Motion      :\033[1;34m Change Type       \033[0;36m|\n");
	ft_putstr("   | 1           :\033[1;34m Change Fractal    \033[0;36m|\n");
	ft_putstr("   | SCROLL  :\033[1;34m DOWN  -Zoom+  UP      \033[0;36m|\n");
	ft_putstr("   | BOUTTON :\033[1;34m RIGHT -Zoom+ LEFT     \033[0;36m|\n");
	ft_putstr("   | X  Intern   Color   Extern  C   \033[0;36m|\n");
	ft_putstr("   | -      -Max Iteration+      +   \033[0;36m|\n");
	ft_putstr("   | Y U I O P { }:\033[1;34m Change Types     \033[0;36m|\n");
	ft_putstr("   -----------------------------------\n\033[0;0m");
}

static void		menu_mandel(void)
{
	ft_putstr("\033[36m\n   ######### \033[1;32mMADE BY ");
	ft_putstr("OBELOUCH \033[0;36m########\n");
	ft_putstr("\033[36m   -----------------------------------\n");
	ft_putstr("   | ESC         :\033[1;34m   Close           \033[0;36m|\n");
	ft_putstr("   | SPACE       :\033[1;34m  Initialize       \033[0;36m|\n");
	ft_putstr("   | Arrows      :\033[1;34m  Move             \033[0;36m|\n");
	ft_putstr("   | 1           :\033[1;34m Change Fractal    \033[0;36m|\n");
	ft_putstr("   | SCROLL  :\033[1;34m DOWN  -Zoom+  UP      \033[0;36m|\n");
	ft_putstr("   | BOUTTON :\033[1;34m RIGHT -Zoom+ LEFT     \033[0;36m|\n");
	ft_putstr("   | X  Intern   Color   Extern  C   \033[0;36m|\n");
	ft_putstr("   | -      -Max Iteration+      +   \033[0;36m|\n");
	ft_putstr("   | N          -Power+          M   \033[0;36m|\n");
	ft_putstr("   -----------------------------------\033[0;0m\n");
}

void			menu(t_fractol f)
{
	if (f.type == NONE)
		error();
	if (f.type == JULIA)
		menu_julia();
	if (f.type != JULIA)
		menu_mandel();
}
