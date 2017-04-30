/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:59:23 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/27 23:59:24 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t i)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	d[i] = '\0';
	ft_memcpy(d, s, i);
	return (d);
}
