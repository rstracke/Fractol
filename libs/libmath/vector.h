/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:05:47 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/17 13:07:15 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# ifndef CMPLX
#  define CMPLX

typedef long double	t_re;
typedef long double	t_im;

# endif

typedef struct	s_vector
{
	t_re		x;
	t_re		y;
	t_re		z;
}				t_vector;

t_vector		vector_init(t_re x, t_re y, t_re z);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_cross(t_vector v1, t_vector v2);
t_re			vector_dot(t_vector v1, t_vector v2);

t_re			vector_mod(t_vector v);
t_vector		vector_scalar(t_vector v, t_re a);
t_vector		vector_unit(t_vector v);

#endif
