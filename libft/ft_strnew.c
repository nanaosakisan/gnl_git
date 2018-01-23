/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:59:26 by iporsenn          #+#    #+#             */
/*   Updated: 2017/11/22 15:59:27 by iporsenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = 0;
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
