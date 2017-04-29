/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 05:07:49 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/29 05:07:50 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isascii(char *str)
{
	size_t i;

	i = 0;
	while (ft_isascii(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}
