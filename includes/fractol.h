/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 11:28:09 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:29:43 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "../libs/libft/libft.h"
# include "../libs/libmath/complex.h"
# include "../libs/libmlx/mlx.h"
# include "color.h"
# include "point.h"
# include "border.h"
# include "f_cl.h"
# include "file.h"
# include "keys.h"

# include "mlx_graphics.h"

# define COLOR_HEADER "includes/color.h"
# define PALETTE_SRC "srcs/palette1.c"
# define GPU_SRC "srcs/gpu_src.cl"

# define TITLE "Fractol by Rstracke"

# define UI unsigned int
# define ZOOM 5.0

# define MANDELBROT 0
# define JULIA 1
# define BIRD 2
# define SHIP 3
# define BUFFALO 4

typedef struct		s_fractol
{
	int				iter_max;
	int				id;
	char			*name;
	t_cmplx			c;
	t_cmplx			z;
	t_point			offset;
	t_border		border;
}					t_fractol;

typedef struct		s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	color;
}					t_rgb;

typedef struct		s_cam
{
	double			zoom;
	t_pixel			mid;
	t_pixel			coord;
	t_pixel			dt;
}					t_cam;

typedef struct		s_global
{
	unsigned int	nb_pix;
	int				palette_id;
	int				width;
	int				height;
	int				rd;
	int				mouse_moved;
	t_fractol		fractol;
	t_cam			cam;
	t_rgb			color;
	t_cl			cl;
	t_mlx			mlx;
}					t_global;

void				init(t_global *g);
void				init_global(t_global *g);
t_cam				init_camera(t_pixel mid, t_pixel coord,
								t_pixel dt, double zoom);
t_rgb				init_rgb(unsigned int red, unsigned int green,
								unsigned int blue, unsigned int color);
void				set_limits(t_fractol *f);
void				calc(t_global *g);
void				put_fractol(t_global *g);
void				load_args_opencl_pt1(t_global *g);
void				load_opencl(t_global *g);
void				cl_destroy(t_cl *cl);
int					on_key_pressed(int key, t_global *g);
int					on_mouse_event(int key, int x, int y, t_global *g);
int					on_mouse_move(int x, int y, t_global *g);
int					expose(t_global *g);
char				*join_and_free(char *s1, char *s2);
void				get_fractol_name(t_fractol *f);
int					destroy(t_global *g);
void				put_image_mlx(t_global *g);
void				set_mid_mouse(t_global *g, int cur_x, int cur_y);

#endif
