/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:30:31 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:58:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		get_fractal_differences(t_global *g)
{
	if (g->fractol.id == JULIA)
	{
		g->fractol.z.re = (g->cam.coord.x - g->cam.mid.x) / g->cam.zoom +
							g->fractol.border.left_up.x + g->fractol.offset.x;
		g->fractol.z.im = (g->cam.coord.y - g->cam.mid.y) / g->cam.zoom +
							g->fractol.border.left_up.y + g->fractol.offset.y;
		g->fractol.c.re = 0.285;
		g->fractol.c.im = 0.01;
	}
	else
	{
		g->fractol.c.re = (g->cam.coord.x - g->cam.mid.x) / g->cam.zoom +
							g->fractol.border.left_up.x + g->fractol.offset.x;
		g->fractol.c.im = (g->cam.coord.y - g->cam.mid.y) / g->cam.zoom +
							g->fractol.border.left_up.y + g->fractol.offset.y;
		g->fractol.z.re = 0;
		g->fractol.z.im = 0;
	}
}

void			put_image_mlx(t_global *g)
{
	mlx_put_image_to_window(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
							g->mlx.img.img_ptr, 0, 0);
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					20, 20, 0xFFFFFF, "fractale : <- | ->");
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					20, 40, 0xFFFFFF, "zoom : scroll");
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					20, 60, 0xFFFFFF, "Reset : r");
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					20, 80, 0xFFFFFF, "Change palette : p");
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					310, 740, 0x000000, "Fractale : ");
	mlx_string_put(g->mlx.mlx_ptr, g->mlx.win.win_ptr,
					420, 740, 0x000000, g->fractol.name);
}

void			get_fractol_name(t_fractol *f)
{
	if (f->id == MANDELBROT)
		f->name = "Mandelbrot";
	if (f->id == JULIA)
		f->name = "Julia";
	if (f->id == BIRD)
		f->name = "Bird";
	if (f->id == SHIP)
		f->name = "Burning ship";
	if (f->id == BUFFALO)
		f->name = "Buffalo";
}

void			put_fractol(t_global *g)
{
	get_fractal_differences(g);
	load_opencl(g);
	put_image_mlx(g);
}

void			calc(t_global *g)
{
	set_limits(&g->fractol);
	put_fractol(g);
	mlx_loop(g->mlx.mlx_ptr);
}
