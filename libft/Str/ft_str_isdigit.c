/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:29:09 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/27 23:29:21 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(char *str)
{
	size_t i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}
