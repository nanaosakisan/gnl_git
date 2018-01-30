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

static int	read_buff(char *buff, char **reste, char **tmp)
{
	int		i;

	if (ft_strlen(*reste))
	{
		(*reste)++;
		buff = ft_strjoin(*reste, buff);
		ft_bzero(*reste, ft_strlen(*reste));
	}
	if (!ft_strchr(buff, '\n'))
		*tmp = ft_strjoin(*tmp, buff);
	else
	{
		if (!*tmp)
			ft_memccpy(*tmp, buff, '\n', ft_strlen(buff));
		else
		{
			i = ft_strlen(*tmp);
			ft_memccpy(*tmp + i, buff, '\n', (ft_strlen(buff)));
		}
		i = 0;
		while (buff[i] != '\n')
			i++;
		*reste = ft_strsub(buff, i, ft_strlen(buff));
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*reste = NULL;
	char		buff[ft_strlen(reste) + BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (0);
	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || ft_strlen(reste))
	{
		buff[ret] = '\0';
		if (!(read_buff((char*)&buff, &reste, &tmp)))
			break;
	}
	if (ret == -1)
		return (-1);
	if (ft_strchr(tmp, '\n'))
		tmp[ft_strlen(tmp) - 1] = '\0';
	else
		tmp[ft_strlen(tmp)] = '\0';
	ft_strcat(*line, ft_strtrim(tmp));
	ft_memdel((void **)&tmp);
	ft_bzero(buff, ft_strlen(buff));
	if (ret == 0 && !ft_strlen(reste) && !ft_strlen(*line))
		return (0);
	return (1);
}
