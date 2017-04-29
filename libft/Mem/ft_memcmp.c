/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:32:47 by tboivin           #+#    #+#             */
/*   Updated: 2016/11/09 03:26:53 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;
	int				cmp;

	str = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = -1;
	while (++i < n)
	{
		cmp = str[i] - str2[i];
		if (cmp != 0)
			return (cmp);
	}
	return (0);
}
