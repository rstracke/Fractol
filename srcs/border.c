/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:38:26 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:36:59 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "border.h"

t_border		init_border(t_point left_up, t_point right_dwn)
{
	t_border	border;

	border.left_up = left_up;
	border.right_dwn = right_dwn;
	return (border);
}
