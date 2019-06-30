/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:53:10 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/07 19:49:17 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "../libs/libft/libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 1000
# endif

typedef struct	s_file
{
	int			fd;
	int			ret_gnl;
	char		*line;
	char		*new_line;
	char		*tmp;
}				t_file;

char			*read_file(char *path);

#endif
