/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:56:10 by iporsenn          #+#    #+#             */
/*   Updated: 2017/11/22 15:56:11 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	if (ft_strlen(s1) == 0)
	{
		ft_memcpy(s1, s2, ft_strlen(s2));
		s1[ft_strlen(s2)] = '\0';
	}
	else
	{
		i = ft_strlen(s1);
		j = -1;
		while (s2[++j])
		{
			s1[i] = s2[j];
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
