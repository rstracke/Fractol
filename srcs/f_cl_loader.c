/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cl_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:05:14 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:01:44 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	load_args_opencl_pt2(t_global *g, int *err)
{
	*err |= clSetKernelArg(g->cl.kernel, 10,
		sizeof(g->fractol.border.right_dwn.x), &g->fractol.border.right_dwn.x);
	*err |= clSetKernelArg(g->cl.kernel, 11,
		sizeof(g->fractol.border.left_up.y), &g->fractol.border.left_up.y);
	*err |= clSetKernelArg(g->cl.kernel, 12,
		sizeof(g->fractol.border.right_dwn.y), &g->fractol.border.right_dwn.y);
	*err |= clSetKernelArg(g->cl.kernel, 13,
		sizeof(g->fractol.c.re), &g->fractol.c.re);
	*err |= clSetKernelArg(g->cl.kernel, 14,
		sizeof(g->fractol.c.im), &g->fractol.c.im);
	*err |= clSetKernelArg(g->cl.kernel, 15,
		sizeof(g->fractol.z.re), &g->fractol.z.re);
	*err |= clSetKernelArg(g->cl.kernel, 16,
		sizeof(g->fractol.z.im), &g->fractol.z.im);
	*err |= clSetKernelArg(g->cl.kernel, 17,
		sizeof(g->fractol.iter_max), &g->fractol.iter_max);
	*err |= clSetKernelArg(g->cl.kernel, 18, sizeof(g->cam.dt.x), &g->cam.dt.x);
	*err |= clSetKernelArg(g->cl.kernel, 19, sizeof(g->cam.dt.y), &g->cam.dt.y);
	*err |= clSetKernelArg(g->cl.kernel, 20,
		sizeof(g->cam.mid.x), &g->cam.mid.x);
	*err |= clSetKernelArg(g->cl.kernel, 21,
		sizeof(g->cam.mid.y), &g->cam.mid.y);
}

void		load_args_opencl_pt1(t_global *g)
{
	int err;

	err = -1;
	err = clSetKernelArg(g->cl.kernel, 0, sizeof(cl_mem), &(g->cl.output));
	err |= clSetKernelArg(g->cl.kernel, 1,
		sizeof(g->fractol.id), &g->fractol.id);
	err |= clSetKernelArg(g->cl.kernel, 2, sizeof(g->width), &g->width);
	err |= clSetKernelArg(g->cl.kernel, 3, sizeof(g->height), &g->height);
	err |= clSetKernelArg(g->cl.kernel, 4, sizeof(g->cam.zoom), &g->cam.zoom);
	err |= clSetKernelArg(g->cl.kernel, 5,
		sizeof(g->fractol.offset.x), &g->fractol.offset.x);
	err |= clSetKernelArg(g->cl.kernel, 6,
		sizeof(g->fractol.offset.y), &g->fractol.offset.y);
	err |= clSetKernelArg(g->cl.kernel, 7, sizeof(g->rd), &g->rd);
	err |= clSetKernelArg(g->cl.kernel, 8, sizeof(g->palette_id),
							&g->palette_id);
	err |= clSetKernelArg(g->cl.kernel, 9,
		sizeof(g->fractol.border.left_up.x), &g->fractol.border.left_up.x);
	load_args_opencl_pt2(g, &err);
	if (err != CL_SUCCESS)
		ft_err(&ft_putendl, "Error with clSetKernelArg");
}

void		load_opencl(t_global *g)
{
	int		err;
	t_cl	*cl;

	cl = &(g->cl);
	err = -1;
	load_args_opencl_pt1(g);
	cl->global = g->nb_pix;
	err = clEnqueueNDRangeKernel(cl->commands, cl->kernel, 1, NULL,
			&cl->global, &cl->local, 0, NULL, NULL);
	if (err)
		ft_err(&ft_putendl, "Error with clEnqueueNDRangeKernel");
	clFinish(cl->commands);
	err = clEnqueueReadBuffer(cl->commands, cl->output, CL_TRUE, 0,
			sizeof(unsigned int) * g->nb_pix, g->mlx.img.data, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		ft_err(&ft_putendl, "Error with clEnqueueReadBuffer");
}
