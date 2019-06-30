/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:00:04 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:27:34 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_GRAPHICS_H
# define MLX_GRAPHICS_H

# ifndef WIN_W
#  define WIN_W 800
# endif

# ifndef WIN_H
#  define WIN_H 800
# endif

# include "../libs/libmlx/mlx.h"
# include "mlx_pixel.h"

typedef	struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				linesize;
	int				endian;
	int				bpp;
	int				width;
	int				height;
}					t_img;

typedef	struct		s_win
{
	void			*win_ptr;
	char			*title;
	int				width;
	int				height;
}					t_win;

typedef	struct		s_mlx
{
	void			*mlx_ptr;
	int				width;
	int				height;
	t_img			img;
	t_win			win;
}					t_mlx;

t_mlx				init_mlx(void *mlx, int width, int height);
t_win				init_win(t_mlx *mlx, char *title, int width, int height);
t_img				init_img(void *mlx, int width, int height);
int					draw_img(void *mlx, void *win, t_img img);
int					put_pix_img(void *mlx, void *mx, t_pixel p);

#endif
