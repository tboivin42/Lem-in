/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isalnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:59:23 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/27 23:59:24 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isalnum(char *str)
{
	size_t i;

	i = 0;
	while (ft_isalnum(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

int		ft_str_isalnum_lem(char *str)
{
	size_t i;

	i = 0;
	while (ft_isalnum_lem(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}
