/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cl_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:45:20 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:44:57 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		load_gpu_src(t_cl *cl)
{
	char	*tmp;

	ft_malloc_check(cl->src.sbegin =
					ft_strdup("#define GPU\n#define UI unsigned int\n"));
	cl->src.scolor = read_file(COLOR_HEADER);
	cl->src.skernel = read_file(GPU_SRC);
	tmp = join_and_free(cl->src.sbegin, cl->src.scolor);
	tmp = join_and_free(tmp, cl->src.skernel);
	cl->src.k_src = tmp;
}

void		cl_destroy(t_cl *cl)
{
	clReleaseProgram(cl->program);
	clReleaseKernel(cl->kernel);
	clReleaseCommandQueue(cl->commands);
	clReleaseContext(cl->context);
	clReleaseMemObject(cl->output);
	free((char *)cl->src.k_src);
}
