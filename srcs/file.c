/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstracke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:07:17 by rstracke          #+#    #+#             */
/*   Updated: 2019/05/13 18:46:46 by rstracke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h>

char		*read_file(char *path)
{
	t_file	file;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if ((file.fd = open(path, O_RDONLY)) < 0)
		ft_err(&perror, "Error opening file");
	file.line = ft_strnew(0);
	while ((ret = read(file.fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		file.tmp = file.line;
		file.line = ft_strjoin(file.tmp, buff);
		free(file.tmp);
	}
	close(file.fd);
	return (file.line);
}
