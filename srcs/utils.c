/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:02:32 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:11:14 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*join_and_free(char *s1, char *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*res;

	tmp1 = s1;
	tmp2 = s2;
	res = ft_strjoin(s1, s2);
	free(tmp1);
	free(tmp2);
	return (res);
}

int			destroy(t_global *g)
{
	cl_destroy(&g->cl);
	mlx_destroy_image(g->mlx.mlx_ptr, g->mlx.img.img_ptr);
	exit(1);
	return (0);
}
