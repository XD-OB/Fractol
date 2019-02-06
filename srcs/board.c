#include "../includes/fractol.h"

void		error(void)
{
	ft_putstr("\033[32Usage: ./fractol  type\n\n");
	ft_putstr("Available fractals:   * Julia\n");
	ft_putstr("                      * LoopJulia\n");
	ft_putstr("                      * StarJulia\n");
	ft_putstr("                      * CantorJulia\n");
	ft_putstr("                      * Mandelbrot\n");
	ft_putstr("                      * Multibrot\n");
	ft_putstr("                      * Tricorn\n");
	ft_putstr("                      * Douady\n");
	ft_putstr("                      * Feigenbaum\n");
	ft_putstr("                      * Cosine\n");
	ft_putstr("                      * BurningShip\n");
	ft_putstr("                      * SJulia\n");
	ft_putstr("                      * Galaxy\n");
	ft_putstr("                      * LeafJulia\n");
	ft_putstr("                      * InfinityCircles\n");
	exit(-1);
}

void	menu_julia(void)
{
	ft_putstr("-----------------------------------\n");
	ft_putstr("ESC         :   Close\n");
	ft_putstr("SPACE       :  Initialize\n");
	ft_putstr("F           : Lock/Free Motion\n");
	ft_putstr("Arrows      :  Move\n");
	ft_putstr("Motion      : Change Type\n");
	ft_putstr("SCROLL :DOWN  -Zoom+  UP\n");
	ft_putstr("BOUTTON:RIGHT -Zoom+ LEFT\n");
	ft_putstr("X  Intern Color Extern  C\n");
	ft_putstr("-    -Max Iteration+    +\n");
	ft_putstr("J         -Power+       K\n");
	ft_putstr("Y U I O P { }:  Change Types\n");
	ft_putstr("------------------------------------\n");
	
}

void	menu_mandel(void)
{
	ft_putstr("-----------------------------------\n");
	ft_putstr("ESC          :   Close\n");
	ft_putstr("SPACE        :  Initialize\n");
	ft_putstr("Arrows       :  Move\n");
	ft_putstr("SCROLL:DOWN  -Zoom+  UP\n");
	ft_putstr("SCROLL:DOWN  -Zoom+  UP\n");
	ft_putstr("X  Intern Color Extern  C\n");
	ft_putstr("-    -Max Iteration+    +\n");
	ft_putstr("N         -Power+       M\n");
	ft_putstr("-----------------------------------\n");

}
