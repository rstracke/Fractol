/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:27:08 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:37:28 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_CL_H
# define F_CL_H

# include <OpenCL/opencl.h>

typedef struct			s_src
{
	const char			*k_src;
	char				*skernel;
	char				*sbegin;
	char				*scolor;
	char				*spalette;
}						t_src;

typedef struct			s_cl
{
	int					err;
	cl_device_id		dev_id;
	cl_context			context;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				output;
	t_src				src;
	size_t				local;
	size_t				global;
}						t_cl;

void					init_cl(t_cl *cl);
void					load_gpu_src(t_cl *cl);

#endif
