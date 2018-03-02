/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:40:12 by iporsenn          #+#    #+#             */
/*   Updated: 2018/01/17 16:40:14 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //daw

int		read_buff(char *buff, char* tmp, char **reste, char **line)
{
	int i;
	int j;

	if (ft_strlen(*reste))
	{
		buff = ft_strjoin(*reste, buff);
		ft_strdel(reste);
	}
	if (!(tmp = (char*)ft_memalloc(ft_strlen(buff) + 1)))
		return (0);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (!ft_strlen(tmp))
			tmp[i] = buff[i];
		else
		{
			j = (int)ft_strlen(tmp);
			tmp[j] = buff[i];
			j++;
		}
		i++;
	}
	if (!(*line))
	{
		if (!(*line = (char*)ft_memalloc(ft_strlen(tmp) + 1)))
			return (0);
	}
	*line = ft_strjoin(*line, tmp);
	ft_strdel(&tmp);
	if (buff[i] == '\n')
	{
		if (!(*reste = (char*)ft_memalloc(ft_strlen(buff) - i)))
			return (0);
		i++;
		ft_strcpy(*reste, buff + i);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *reste = NULL;
	char		*buff;
	char		*tmp;
	int			ret;

	tmp = NULL;
	*line = NULL;
	ret = 0;
	buff = NULL;
	if (fd < 0 || !line)
		return (-1);
	if (!(buff = (char*)ft_memalloc(BUFF_SIZE + 1)))
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (read_buff(buff, tmp, &reste, line) == 1)
			return(1);
	}
	ft_strdel(&buff);
	if (ft_strlen(reste) == 0 && ret == 0)
	{
		ft_strdel(&reste);
		return (0);
	}
	return (1);
}
