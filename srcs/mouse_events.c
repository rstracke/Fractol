/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:50:56 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:13:34 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mid_mouse(t_global *g, int cur_x, int cur_y)
{
	g->fractol.offset.x -= ((double)(g->cam.mid.x - cur_x)) / g->cam.zoom;
	g->fractol.offset.y -= ((double)(g->cam.mid.y - cur_y)) / g->cam.zoom;
	g->cam.mid.x = cur_x;
	g->cam.mid.y = cur_y;
}

int		expose(t_global *g)
{
	put_fractol(g);
	return (0);
}

int		on_mouse_move(int x, int y, t_global *g)
{
	if (g->fractol.id == JULIA && g->mouse_moved != -1 &&
			x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H)
	{
		g->cam.dt.x = x;
		g->cam.dt.y = y;
		g->mouse_moved = 1;
		put_fractol(g);
	}
	return (0);
}

int		on_mouse_event(int key, int x, int y, t_global *g)
{
	if (key == 1 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
		set_mid_mouse(g, x, y);
	if (key == 5 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		set_mid_mouse(g, x, y);
		g->cam.zoom *= 1.1;
		g->fractol.iter_max += 1;
		put_fractol(g);
	}
	if (key == 4 && x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		set_mid_mouse(g, x, y);
		g->cam.zoom /= 1.1;
	}
	put_fractol(g);
	return (0);
}
