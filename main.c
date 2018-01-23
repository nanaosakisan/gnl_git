/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:51:23 by iporsenn          #+#    #+#             */
/*   Updated: 2018/01/05 14:51:25 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc < 2)
		return (0);
	else
	{
		if((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		while (get_next_line(fd, &line))
		{
			ft_putendl("apres gnl");
			ft_putstr(line);
		}
	}
	if (close(fd) == -1)
		return (0);
	return (0);
}
