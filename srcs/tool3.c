/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 00:45:48 by tboivin           #+#    #+#             */
/*   Updated: 2017/05/15 00:45:49 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	if_froom(char *line)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && ft_isdigit(line[i + 1]))
			j++;
		i++;
	}
	if (j == 2)
		ft_exit("Error");
	free(line);
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
