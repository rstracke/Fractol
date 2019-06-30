/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:23:46 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 19:25:20 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORDER_H
# define BORDER_H

# include "point.h"

typedef struct		s_brd
{
	t_point			left_up;
	t_point			right_dwn;
}					t_border;

t_border			init_border(t_point left_up, t_point right_dwn);

#endif
