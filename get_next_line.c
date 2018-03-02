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

static char	*join_free(char *s1, char *s2)
{
	char	*ret;
	int 	i;
	int 	j;
	int 	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	i = -1;
	j = 0;
	while (s1[++i])
	{
		ret[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i])
	{
		ret[j] = s2[i];
		j++;
	}
	return (ret);
}
char	*ft_strccpy(char *dst, const char *src, int c, size_t n)
{
	char			*ret;
	unsigned char	car;
	int				i;
	int				size;

	car = c;
	size = ft_strlen(dst) + n;
	if (!n)
		return(NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(ret, size);
	i = 0;
	while (dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	if (src[0] == c)
		return (ret);
	while (n > 0)
	{
		ret[i] = *src;
		if (ret[i] == car)
		{
			ft_strdel(&dst);
			return (ret);
		}
		n--;
		i++;
		src++;
	}
	return (NULL);
}

static int	read_buff(char *buff, char **reste, char **tmp)
{
	int	i;

	if (ft_strlen(*reste))
	{
		buff = ft_strcat(*reste, buff);
		ft_memdel((void**)reste);
	}
	if (!ft_strchr(buff, '\n'))
		*tmp = join_free(*tmp, buff);
	else
	{
		*tmp = ft_strccpy(*tmp, buff, '\n', ft_strlen(buff));
		i = 0;
		while (buff[i] != '\n')
			i++;
		*reste = ft_strsub(buff, i + 1, ft_strlen(buff) - 1);
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

	if (fd < 0 || !line)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (0);
	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || ft_strlen(reste))
	{
		buff[ret] = '\0';
		if (!(read_buff(buff, &reste, &tmp)))
			break ;
	}
	if (ret == -1)
		return (-1);
	ft_strcat(*line, ft_strtrim(tmp));
	if (ret == 0 && !ft_strlen(reste) && !ft_strlen(*line))
		return (0);
	return (1);
}
