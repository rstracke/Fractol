/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:06:18 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:49:24 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_fractol_up(t_global *g)
{
	g->mouse_moved = 0;
	g->fractol.id += 1;
	if (g->fractol.id >= 5)
		g->fractol.id = 0;
	set_limits(&g->fractol);
	get_fractol_name(&g->fractol);
}

static void	key_fractol_down(t_global *g)
{
	g->mouse_moved = 0;
	g->fractol.id -= 1;
	if (g->fractol.id < 0)
		g->fractol.id = 0;
	set_limits(&g->fractol);
	get_fractol_name(&g->fractol);
}

static void	key_palette(t_global *g)
{
	g->palette_id += 1;
	if (g->palette_id == 6)
		g->palette_id = 0;
}

static int	move(int key, t_global *g)
{
	if (key == KEY_LEFT)
		g->fractol.offset.x += 10.0 / g->cam.zoom;
	else if (key == KEY_RIGHT)
		g->fractol.offset.x -= 10.0 / g->cam.zoom;
	if (key == KEY_UP)
		g->fractol.offset.y += 10.0 / g->cam.zoom;
	else if (key == KEY_DOWN)
		g->fractol.offset.y -= 10.0 / g->cam.zoom;
	return (key);
}

int			on_key_pressed(int key, t_global *g)
{
	if (key == KEY_ESCAPE)
		destroy(g);
	if (key == KEY_SPACEBAR)
		g->mouse_moved = (g->mouse_moved == -1) ? 1 : -1;
	if (key == KEY_R)
	{
		g->rd = 32;
		g->cam.mid = init_pixel(WIN_W / 2, WIN_H / 2, 0);
		g->cam.zoom = 200;
		set_limits(&g->fractol);
	}
	if (key == KEY_P)
		key_palette(g);
	if (key == KEY_PAD_4)
		key_fractol_down(g);
	if (key == KEY_PAD_6)
		key_fractol_up(g);
	if (key == KEY_R || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_P)
		put_fractol(g);
	if (move(key, g))
		put_fractol(g);
	return (0);
}
