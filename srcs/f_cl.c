/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:50:19 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:37:38 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_cl.h"
#include "../libs/libft/libft.h"
#include "../includes/mlx_graphics.h"

static void		try_opencl_init(t_cl *cl)
{
	int nb;

	nb = WIN_H * WIN_W * 3;
	load_gpu_src(cl);
	cl->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &cl->dev_id, NULL);
	if (cl->err != CL_SUCCESS)
		ft_err(&ft_putendl, "Error with clGetDeviceIDs");
	cl->context = clCreateContext(0, 1, &cl->dev_id, NULL, NULL, &cl->err);
	if (!cl->context)
		ft_err(&ft_putendl, "Error with clCreateContext");
	cl->commands = clCreateCommandQueue(cl->context, cl->dev_id, 0, &cl->err);
	if (!cl->commands)
		ft_err(&ft_putendl, "Error with clCreateCommandQueue");
	cl->program = clCreateProgramWithSource(cl->context, 1,
								(const char **)&cl->src.k_src, NULL, &cl->err);
	cl->err = clBuildProgram(cl->program, 0, NULL, NULL, NULL, NULL);
	if (cl->err != CL_SUCCESS)
		ft_err(&ft_putendl, "Error with clBuildProgram");
	cl->kernel = clCreateKernel(cl->program, "choose_fractal", &cl->err);
	if (!cl->kernel || cl->err != CL_SUCCESS)
		ft_err(&ft_putendl, "Error with clCreateKernel");
	cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,
								sizeof(unsigned int) * nb, NULL, NULL);
	if (!cl->output)
		ft_err(&ft_putendl, "Error with clCreateBuffer");
}

void			init_cl(t_cl *cl)
{
	try_opencl_init(cl);
}
