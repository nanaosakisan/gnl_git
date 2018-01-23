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
	reste = (reste != NULL) ? reste : NULL;
	// if (reste != NULL)
	// {
	// 	ft_putendl("if reste");
	// 	i = -1;
	// 	while (reste[++i] == '\n')
	// 		;
	// 	tmp = ft_strsub(reste, i, ft_strlen(reste));
	// 	ft_putstr("tmp : ");
	// 	ft_putstr(tmp);
	// 	ft_memdel((void**)&reste);
	// 	i = -1;
	// 	while (tmp[++i] != '\n')
	// 		;
	// 	reste = ft_strsub(tmp, i, (size_t)ft_strlen(tmp));
	// 	ft_putstr("reste : ");
	// 	ft_putnbr(ft_strlen(reste));
	// 	ft_putstr(reste);
	// 	if (ft_strlen(reste) == 0)
	// 		ft_memdel((void**)&reste);
	// }
	while ((ret = read(fd, buff, BUFF_SIZE)) >= 0 && !ft_strchr(tmp, '\n'))
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
		{
			tmp = ft_strjoin(tmp, buff);
			i = -1;
			while (buff[++i] != '\n')
				;
			reste = ft_strsub(buff, i, (size_t)BUFF_SIZE);
		}
		else
			ft_strcat(tmp, buff);
	}
	ft_putstr("tmp = ");
	ft_putstr(tmp);
	ft_memccpy(*line, tmp, '\n', ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	if (ret > 0 || reste != NULL)
		return (1);
	else
		return (0);
}
