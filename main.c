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

int				main(void)
{
	char		*line;
	int			fd;

	fd = open("test", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putstr("line = ");
		ft_putendl(line);
	}
	close(fd);
	return (0);
}
