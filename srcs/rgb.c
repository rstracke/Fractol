/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:04:47 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:15:37 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		init_rgb(unsigned int red, unsigned int green,
						unsigned int blue, unsigned int color)
{
	t_rgb	rgb;

	rgb.red = red;
	rgb.green = green;
	rgb.blue = blue;
	rgb.color = color;
	return (rgb);
}
