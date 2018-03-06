 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:22:00 by iporsenn          #+#    #+#             */
/*   Updated: 2018/01/30 15:22:02 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	char		*filename;

	filename = "one_big_fat_line.txt";
	fd = open(filename, O_RDONLY);
	line = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
		ft_putendl(line);
	close(fd);
	return (0);
}
