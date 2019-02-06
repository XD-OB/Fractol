/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/06 20:25:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	switch_design(t_graphic *ptr)
{
	if (ptr->design != 9)
		ptr->design++;
	else
		ptr->design = 0;
}

static void	switch_intern(t_graphic *ptr)
{
	if (ptr->intern == 5)
		ptr->intern = 0;
	else
		ptr->intern++;
}

int		change_map(int k)
{
	int	design[16];

        design[0] = 0x33CCCC;
        design[1] = 0x009933;
        design[2] = 0x00C800;
        design[3] = 0xBFFF00;
        design[4] = 0x00FF7F;
		design[5] = 0x00BFFF;
        design[6] = 0x007FFF;
        design[7] = 0x0000FF;
        design[8] = 0x7F00FF;
        design[9] = 0xFF007F;
        design[10] = 0xFF0000;
        design[11] = 0xFF3F00;
		design[12] = 0xFF7F00;
        design[13] = 0xFFBF00;
        design[14] = 0xFFB3E6;
        design[15] = 0xFFFF00;
	return (design[k % 16]);
}

int            change_map2(int k)
{
	int	design[16];

        design[0] = 0x00FF00;
        design[1] = 0x10DA50;
        design[2] = 0x200210;
        design[3] = 0x301488;
        design[4] = 0x405922;
                design[5] = 0x50ADAD;
        design[6] = 0x60AD90;
        design[7] = 0x70BBCC;
        design[8] = 0x80DABC;
        design[9] = 0x902121;
        design[10] = 0xA032A3;
        design[11] = 0xB0AB12; 
                design[12] = 0xC08243;
        design[13] = 0xD06555;
        design[14] = 0xE01341;
        design[15] = 0xF0FFFF;
	return (design[k % 16]);
}

int		change_map3(int k)
{
	int	design[65];
 
        design[0] = 0x0;
        design[1] = 0x000404;
        design[2] = 0x000808;
        design[3] = 0x000C0C;
                design[4] = 0x001010;
        design[5] = 0x001414;
        design[6] = 0x001818;
        design[7] = 0x001C1C;
        design[8] = 0x002020;
        design[9] = 0x002424; 
                design[10] = 0x002828;
        design[11] = 0x002C2C;
        design[12] = 0x003030;
        design[13] = 0x003434;
        design[14] = 0x003838;
        design[15] = 0x003C3C;
        design[16] = 0x004040;
        design[17] = 0x004444;
        design[18] = 0x004848;
        design[19] = 0x004C4C;
        design[20] = 0x005050;
        design[21] = 0x005454;
        design[22] = 0x005858;
        design[23] = 0x005C5C;
        design[24] = 0x006060;
        design[25] = 0x006464;
        design[26] = 0x006868;
        design[27] = 0x006C6C;
        design[28] = 0x007070;
        design[29] = 0x007474;
        design[30] = 0x007878;
        design[31] = 0x007C7C;
        design[32] = 0x008080;	
        design[33] = 0x008484;	
        design[34] = 0x008888;	
        design[35] = 0x008C8C;	
        design[36] = 0x009090;	
        design[37] = 0x009494;	
        design[38] = 0x009898;	
        design[39] = 0x009C9C;	
        design[40] = 0x00A0A0;	
        design[41] = 0x00A4A4;	
        design[42] = 0x00A8A8;	
        design[43] = 0x00ACAC;	
        design[44] = 0x00B0B0;	
        design[45] = 0x00B4B4;	
        design[46] = 0x00B8B8;	
        design[47] = 0x00BCBC;	
        design[48] = 0x00C0C0;	
        design[49] = 0x00C4C4;	
        design[50] = 0x00C8C8;	
        design[51] = 0x00CCCC;	
        design[52] = 0x00D0D0;	
        design[53] = 0x00D4D4;	
        design[54] = 0x00D8D8;	
        design[55] = 0x00DCDC;	
        design[56] = 0x00E0E0;	
        design[57] = 0x00E4E4;	
        design[58] = 0x00E8E8;	
        design[59] = 0x00ECEC;	
        design[60] = 0x00F0F0;	
        design[61] = 0x00F4F4;	
        design[62] = 0x00F8F8;	
        design[63] = 0x00FCFC;	
        design[64] = 0x00FFFF;	
	return	(design[k % 65]);
}

static void		julia_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_K)
		ptr->j_puis++;
	else if (keycode == K_J)
		ptr->j_puis--;
	else if (keycode == K_Y)
		ptr->j_cte = complex(-0.8, 0.4);
	else if (keycode == K_U)
		ptr->j_cte = complex(-1.417022285618, 0.0099534);
	else if (keycode == K_I)
		ptr->j_cte = complex(-1.476, 0);
	else if (keycode == K_O)
		ptr->j_cte = complex(-0.038088, 0.9754633);
	else if (keycode == K_P)
		ptr->j_cte = complex(0.3, 0.5);
	else if (keycode == K_OPEN_ACO)
		ptr->j_cte = complex(-0.8, 0);
	else if (keycode == K_CLOSE_ACO)
		ptr->j_cte = complex(-0, 1);
}

static void		brot_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_M)
		ptr->m_puis++;
	else if (keycode == K_N && ptr->m_puis >= 0)
		ptr->m_puis--;
}

int			mouse_event(int mousecode, int x, int y, t_fractol *r)
{
	
	if (mousecode == SCROLL_UP || mousecode == B_LEFT)
		ft_zoom(x, y, r);
	if (mousecode == SCROLL_DOWN || mousecode == B_RIGHT)
		ft_unzoom(x, y, r);
	fractal(r->ptr, r);
	return (1);
}

int			mouse_move(int x, int y, t_fractol *r)
{
	t_complex	*c;

	c = &(r->ptr->j_cte);
	if (r->ptr->type == JULIA && x > 0 && y > 0 && y < HEIGHT && x < WIDTH && r->mouse.isclick == 1)
	{
		c->re = (float)WIDTH / 1200 - (float)x / 1000; 
		c->im = (float)HEIGHT / 1200 - (float)y / 1000;
	}
		fractal(r->ptr, r);
	return (1);
}

int			win_close(t_fractol *r)
{
	(void)r;
	exit(0);
	return (0);
}

int			key_press(int keycode, t_fractol *r)
{
	t_mouse		*mouse;

	mouse = &(r->mouse);
	if (keycode == K_F)
	{
		if (mouse->isclick == 0)
			mouse->isclick = 1;
		else
			mouse->isclick = 0;
	}
	return (0);
}

int			key_event(int keycode, t_fractol *r)
{
	t_mouse		*mouse;

	mouse = &(r->mouse);
	if (keycode == K_ESC)
		exit(1);
	else if (keycode == K_X)
		switch_intern(r->ptr);
	else if (keycode == K_C)
		switch_design(r->ptr);
	else if (keycode == K_PLUS)
		r->ptr->max_iter += 10;
	else if (keycode == K_MINUS && r->ptr->max_iter > 10)
		r->ptr->max_iter -= 5;
	else if (keycode == K_P && r->ptr->type == INFCIRCLE)
	{
		if (r->ptr->design == 0)
			r->ptr->design = 1;
		else
			r->ptr->design = 0;
	}
	else if (keycode == K_UP)
		mouse->y -= 30 / r->ptr->zoom;
	else if (keycode == K_DOWN)
		mouse->y += 30 / r->ptr->zoom;
	else if (keycode == K_LEFT)
		mouse->x -= 30 / r->ptr->zoom;
	else if (keycode == K_RIGHT)
		mouse->x += 30 / r->ptr->zoom;
	if (r->ptr->type == JULIA)
		julia_event(keycode, r->ptr);
	if (r->ptr->type != MANDELBROT && r->ptr->type != JULIA)
		brot_event(keycode, r->ptr);
	if (keycode == K_SPACE)
	{
		init_mouse(&(r->mouse));
		init_ptr(r->ptr);
	}
	fractal(r->ptr, r);
	return (1);
}
