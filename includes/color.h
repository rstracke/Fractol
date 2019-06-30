/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <rstracke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:45:48 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 12:32:54 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define WHITE 16777215
# define VERT 1817755
# define BLEU_FONCE 4484275
# define VIOLET 6697881
# define BLEU_CLAIR 1684990
# define JAUNE 16044095
# define ORANGE 15890507
# define ROUGE 15869459
# define BLACK 0x000000

# define MANDELBROT 0
# define JULIA 1
# define BIRD 2
# define SHIP 3
# define BUFFALO 4

typedef struct		s_color
{
	double			nu;
	double			nu_frac;
	double			red;
	double			green;
	double			blue;
	double			mult;
	int				i;
	int				iter_max;
}					t_color;

void				init_color(t_color *s, int i, double mult, int iter_max);
unsigned int		aqua(int iter_max, int i, double mult);
unsigned int		smooth_aqua(int iter_max, int i, double mult);
unsigned int		shade(int i, int iter_max, double mult);
unsigned int		smooth_shade(int i, int iter_max, double mult);
unsigned int		rainbow(int iter_max, int i, double mult);
unsigned int		picots(int iter_max, int i, double squares, double mult);
unsigned int		wow(double zi);

#endif
