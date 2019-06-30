/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:31:21 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:50:23 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_lim_bird_ship(t_fractol *f)
{
	if (f->id == SHIP)
		f->border = init_border(init_point(-2.1, -2.3), init_point(1.5, 1.9));
	else if (f->id == BIRD)
		f->border = init_border(init_point(-1.6, -1.5), init_point(1.5, 1.9));
	f->iter_max = 40;
}

static void	set_lim_mandelbrot(t_fractol *f)
{
	f->border = init_border(init_point(-2.0, -1.5), init_point(1.0, 1.5));
	f->iter_max = 40;
}

static void	set_lim_julia(t_fractol *f)
{
	f->border = init_border(init_point(-1.5, -1.6), init_point(1.0, 1.2));
	f->iter_max = 80;
}

static void	set_lim_buffalo(t_fractol *f)
{
	f->border = init_border(init_point(-2.3, -1.9), init_point(1.0, 1.5));
	f->iter_max = 40;
}

void		set_limits(t_fractol *f)
{
	if (f->id == MANDELBROT)
		set_lim_mandelbrot(f);
	else if (f->id == JULIA)
		set_lim_julia(f);
	else if (f->id == BIRD)
		set_lim_bird_ship(f);
	else if (f->id == SHIP)
		set_lim_bird_ship(f);
	else if (f->id == BUFFALO)
		set_lim_buffalo(f);
	f->offset.x = 1.5;
	f->offset.y = 1.5;
}
