/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:05:31 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/17 13:06:54 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# ifndef CMPLX
#  define CMPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

typedef struct	s_quat
{
	t_re		s;
	t_re		i;
	t_re		j;
	t_re		k;
}				t_quat;

t_quat			quat_init(t_re s, t_re i, t_re j, t_re k);
t_quat			quat_add(t_quat q1, t_quat q2);
t_quat			quat_sub(t_quat q1, t_quat q2);
t_quat			quat_prod(t_quat q1, t_quat q2);
t_quat			quat_div(t_quat q1, t_quat q2);
t_quat			quat_scalar(t_quat q, t_re k);
t_quat			quat_conj(t_quat q);
t_quat			quat_inv(t_quat q);
t_re			quat_mod(t_quat q);

#endif
