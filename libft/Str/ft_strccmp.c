/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:02:09 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/27 23:02:11 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strccmp(const char *s1, const char *s2, int c)
{
	return (ft_memcmp(s1, s2, ft_strclen(s1, c) + 1));
}

int		ft_strcccmp(const char *s1, const char *s2, int c)
{
	return (ft_memcmp(s1, s2, ft_strclen(s1, c)));
}
