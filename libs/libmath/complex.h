/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:08:35 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/17 13:08:29 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>

# ifndef CMPLX
#  define CMPLX

typedef double	t_re;
typedef double	t_im;

# endif

typedef struct	s_cmplx
{
	t_re		re;
	t_im		im;
}				t_cmplx;

t_cmplx			cmplx_init(t_re re, t_im im);
t_cmplx			cmplx_add(t_cmplx z1, t_cmplx z2);
t_cmplx			cmplx_sub(t_cmplx z1, t_cmplx z2);
t_cmplx			cmplx_mult(t_cmplx z1, t_cmplx z2);
t_cmplx			cmplx_conj(t_cmplx z);
t_re			cmplx_mod(t_cmplx z);
t_cmplx			cmplx_scalar(t_cmplx z, t_re re);

#endif
