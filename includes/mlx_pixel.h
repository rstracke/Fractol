/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:10:15 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:27:02 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_PIXEL_H
# define MLX_PIXEL_H

typedef	struct		s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}					t_pixel;

t_pixel				init_pixel(int x, int y, unsigned int color);
int					check_pixel(t_pixel pixel, int width, int height);

#endif
