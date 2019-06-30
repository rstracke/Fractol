/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:59:44 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:04:09 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_graphics.h"
#include <stdlib.h>

t_mlx		init_mlx(void *mlx, int width, int height)
{
	t_mlx	mx;

	mx.mlx_ptr = mlx;
	mx.width = width;
	mx.height = height;
	return (mx);
}

t_win		init_win(t_mlx *mlx, char *title, int width, int height)
{
	t_win	win;

	win.title = title;
	win.width = (width < 0 || width > mlx->width) ? mlx->width : width;
	win.height = (height < 0 || width > mlx->height) ? mlx->height : height;
	win.win_ptr = mlx_new_window(mlx->mlx_ptr,
									win.width, win.height, win.title);
	return (win);
}

t_img		init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	if (!img.img_ptr)
	{
		img.data = NULL;
		return (img);
	}
	img.data = mlx_get_data_addr(img.img_ptr,
												&img.bpp,
												&img.linesize,
												&img.endian);
	return (img);
}
