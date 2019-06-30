/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 00:15:07 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:08:55 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	usage(void)
{
	ft_putstr("Usage: ./fractol [mandelbrot | -m / julia | -j / bird | -d / ");
	ft_putendl("ship | -s / buffalo | -b]");
	exit(1);
}

static void	set_fract(t_fractol *f, int id, char *name)
{
	f->id = id;
	f->name = name;
}

static void	parse_fract(t_fractol *f, char *argv)
{
	if (ft_strequ("mandelbrot", argv) || ft_strequ("-m", argv))
		set_fract(f, MANDELBROT, "mandelbrot");
	else if (ft_strequ("julia", argv) || ft_strequ("-j", argv))
		set_fract(f, JULIA, "julia");
	else if (ft_strequ("bird", argv) || ft_strequ("-d", argv))
		set_fract(f, BIRD, "bird");
	else if (ft_strequ("ship", argv) || ft_strequ("-s", argv))
		set_fract(f, SHIP, "ship");
	else if (ft_strequ("buffalo", argv) || ft_strequ("-b", argv))
		set_fract(f, BUFFALO, "buffalo");
	else
		usage();
}

int			main(int argc, char **argv)
{
	t_global	global;

	if (argc != 2)
		usage();
	parse_fract(&global.fractol, argv[1]);
	init(&global);
	calc(&global);
}
