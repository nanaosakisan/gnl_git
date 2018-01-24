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
	static char	*reste;
	int			i;

	if (!fd || fd < 0)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (0);
	ret = 0;
	reste = ((reste) ? reste : NULL);
	if (reste)
	{
		while (*reste == '\n')
			reste++;
		ft_strcat(tmp, reste);
		ft_bzero(&reste, ft_strlen(reste));
		i = -1;
		if (tmp[++i] == '\n')
			i++;
		else
			reste = ft_strsub(tmp, i, (size_t)ft_strlen(tmp));

	}
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0 && !ft_strchr(tmp, '\n'))
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(buff, '\n') != NULL)
		{
			i = 0;
			while (buff[i] != '\n')
				i++;
			reste = ft_strsub(buff, i, (size_t)BUFF_SIZE);
		}
	}
	ft_strcat(reste, buff);
	ft_putstr(reste);
	ft_memccpy(*line, tmp, '\n', ft_strlen(tmp));
	// ft_putstr(*line);
	ft_memdel((void **)&tmp);
	if (ret == 0 && !reste)
		return (0);
	else
		return (1);
}
