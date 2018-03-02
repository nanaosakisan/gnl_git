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

int		read_reste(char **reste, char **tmp, char **line)
{
	int i;
	int end;

	if (*reste[0] == '\n')
		(*reste)++;
	end = 0;
	if (!(*line = (char*)ft_memalloc(ft_strlen(*reste) + 1)))
		return (-1);
	i = 0;
	while ((*reste)[i] != '\n' && (*reste)[i] != '\0')
	{
		(*line)[i] = (*reste)[i];
		i++;
	}
	if ((*reste)[i] == '\n')
		end = 1;
	if (!(*tmp = (char*)ft_memalloc(ft_strlen(*reste) - i + 1)))
		return (-1);
	ft_strcpy(*tmp, *reste + i);
	ft_bzero(*reste, (int)ft_strlen(*reste));
	ft_strcpy(*reste, *tmp);
	ft_strdel(tmp);
	if (end == 1)
		return (1);
	return (0);
}

int		read_buff(char *buff, char **tmp, char **line, char **reste)
{
	int 	i;
	size_t	len;

	len = ft_strlen(buff);
	if (!(*tmp = ft_memalloc(len + 1)))
		return (-1);
	i = -1;
	while (buff[++i] != '\n' && buff[i])
		(*tmp)[i] = buff[i];
	if (!(*line))
		if (!(*line = (char*)ft_memalloc(ft_strlen(*tmp) + 1)))
			return (-1);
	*line = ft_strjoin(*line, *tmp);
	ft_strdel(tmp);
	if (buff[i] == '\n')
	{
		if (!(*reste = (char*)ft_memalloc(len - i + 1)))
			return (-1);
		i++;
		ft_strcpy(*reste, buff + i);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buff;
	char		*tmp;
	static char	*reste = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	tmp = NULL;
	buff = NULL;
	if (ft_strlen(reste))
		if ((read_reste(&reste, &tmp, line)) == 1)
			return (1);
	if (!(buff = (char*)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (read_buff(buff, &tmp, line, &reste) == 1)
			return (1);
	}
	if (!ft_strlen(reste) && ret == 0 && !ft_strlen(*line))
		return (0);
	return (ret != -1) ? 1 : -1;
}
