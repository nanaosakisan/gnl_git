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

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*reste = NULL;
	int			i;

	if (!fd || fd < 0)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (0);
	ret = 0;
	if (ft_strlen(reste))
	{
		while (*reste == '\n')
			reste++;
		ft_strcat(tmp, reste);
		i = 0;
		if (tmp[i] != '\n')
			i++;
		else
			reste = ft_strsub(tmp, i, (size_t)ft_strlen(tmp));
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!ft_strchr(buff, '\n'))
		{
			ft_putendl("entree if");
			tmp = ft_strjoin(tmp, buff);
		}
		else
		{
			if (!tmp)
				ft_memccpy(tmp, buff, '\n', ft_strlen(buff));
			else
			{
				i = ft_strlen(tmp);
				ft_memccpy(tmp + i, buff, '\n', (ft_strlen(buff) - 1));
				ft_putstr("tmp else :");
				ft_putendl(tmp);
			}
			i = 0;
			while (buff[i] != '\n')
				i++;
			reste = ft_strsub(buff, i, ft_strlen(buff));
			break;
		}
	}

	ft_strcat(*line, tmp);
	ft_memdel((void **)&tmp);
	if (ret == 0 && !ft_strlen(reste))
		return (0);
	else
		return (1);
}
