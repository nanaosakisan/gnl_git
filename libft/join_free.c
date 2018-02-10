/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:20:06 by iporsenn          #+#    #+#             */
/*   Updated: 2018/02/06 15:20:08 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_free(char **s1, char *s2)
{
	char	*dest;

	if (!*s1 || !s2)
		return (0);
	dest = 0;
	if (!(dest = ft_strnew(ft_strlen(*s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(dest, *s1);
	ft_strcat(dest, (s2));
	ft_memdel((void**)s1);
	return (dest);
}
