/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:46:26 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:00:12 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_graph(void *m)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)m;
	*mlx = init_mlx(mlx_init(), WIN_W, WIN_H);
	mlx->win = init_win(mlx, TITLE, WIN_W, WIN_H);
	mlx->img = init_img(mlx->mlx_ptr, WIN_W, WIN_H);
}

void		init_global(t_global *g)
{
	g->mlx.mlx_ptr = NULL;
	g->mlx.win.win_ptr = NULL;
	g->mlx.img.img_ptr = NULL;
	g->nb_pix = WIN_W * WIN_H;
	g->rd = 32;
	g->width = WIN_W;
	g->height = WIN_H;
	g->fractol.z = cmplx_init(0, 0);
	g->fractol.c = cmplx_init(0, 0);
	g->fractol.offset = init_point(0, 0);
	g->fractol.border = init_border(init_point(0, 0), init_point(0, 0));
	g->fractol.iter_max = 0;
	g->cam.mid = init_pixel(WIN_W / 2, WIN_H / 2, 0);
	g->cam.coord = init_pixel(0, 0, 0);
	g->cam.dt = init_pixel(WIN_W / 2, WIN_H / 2, 0);
	g->cam.zoom = 200;
	g->color = init_rgb(0, 0, 0, 0);
	g->palette_id = 0;
	g->cl.global = 0;
	g->cl.local = 64;
}

static void	init_hooks(t_global *g)
{
	mlx_expose_hook(g->mlx.win.win_ptr, &expose, g);
	mlx_mouse_hook(g->mlx.win.win_ptr, &on_mouse_event, g);
	mlx_hook(g->mlx.win.win_ptr, 17, 0, &destroy, g);
	mlx_hook(g->mlx.win.win_ptr, 2, 0, &on_key_pressed, g);
	mlx_hook(g->mlx.win.win_ptr, 6, 0, on_mouse_move, g);
}

void		init(t_global *g)
{
	init_global(g);
	init_cl(&g->cl);
	init_graph(&g->mlx);
	init_hooks(g);
}
