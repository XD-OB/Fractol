/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:51 by obelouch          #+#    #+#             */
/*   Updated: 2019/02/04 11:33:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	switch_design(t_graphic *ptr)
{
	if (ptr->design != 7)
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

void		change_map(t_graphic *ptr)
{
        ptr->map[0] = rgb_map(51, 204, 204);
        ptr->map[1] = rgb_map(0, 153, 51);
        ptr->map[2] = rgb_map(0, 200, 0);
        ptr->map[3] = rgb_map(191, 255, 0);
        ptr->map[4] = rgb_map(0, 255, 127);
		ptr->map[5] = rgb_map(0, 191, 255);
        ptr->map[6] = rgb_map(0, 127, 255);
        ptr->map[7] = rgb_map(0, 0, 255);
        ptr->map[8] = rgb_map(127, 0, 255);
        ptr->map[9] = rgb_map(255, 0, 127);
        ptr->map[10] = rgb_map(255, 0, 0);
        ptr->map[11] = rgb_map(255, 63, 0);
		ptr->map[12] = rgb_map(255, 127, 0);
        ptr->map[13] = rgb_map(255, 191, 0);
        ptr->map[14] = rgb_map(255, 179, 230);
        ptr->map[15] = rgb_map(255, 255, 0);
}

static void		julia_event(int keycode, t_graphic *ptr)
{
	if (keycode == K_K)
		ptr->j_puis++;
	else if (keycode == K_J)
		ptr->j_puis--;
	else if (keycode == K_7)
		ptr->j_cte.re += JULIA_C;
	else if (keycode == K_8)
		ptr->j_cte.im += JULIA_C;
	else if (keycode == K_4)
		ptr->j_cte.re -= JULIA_C;
	else if (keycode == K_5)
		ptr->j_cte.im -= JULIA_C;
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

int			mouse_event(int mousecode, int x, int y, t_ready *r)
{
	
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, r);
	if (mousecode == 5 || mousecode == 2)
		ft_unzoom(x, y, r);
	fractal(r->ptr, r);
	return (1);
}

int			key_event(int keycode, t_ready *r)
{
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
	else if (keycode == K_2)
		r->ptr->zoom -= 0.05;
	else if (keycode == K_1)
		r->ptr->zoom += 0.05;
	else if (keycode == K_P && r->ptr->type == INFCIRCLE)
		r->ptr->design == 0 ? (r->ptr->design = 1) : (r->ptr->design = 0);
	if (r->ptr->type == JULIA)
		julia_event(keycode, r->ptr);
	if (r->ptr->type != MANDELBROT && r->ptr->type != JULIA)
		brot_event(keycode, r->ptr);
	if (keycode == K_SPACE)
		init_ptr(r->ptr);
	fractal(r->ptr, r);
	return (1);
}
