/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 03:48:40 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/26 03:48:42 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	check_room(t_room *room)
{
	t_room *tmp;

	while (room->next)
	{
		tmp = room;
		while (tmp)
		{
			if (tmp->next)
			{
				if (*room->line != '#' && *tmp->next->line != '#' &&
					ft_strccmp(room->line, tmp->next->line, ' ') == 0)
				{
					ft_printf("[%s] [%s]\n", tmp->next->line, room->line);
					ft_exit("Error: Identical room");
				}
			}
			tmp = tmp->next;
		}
		room = room->next;
	}
	free(tmp);
}

int 	chr_tube(t_lem *lem, char *line)
{
	int i;

	(void)lem;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-' && (ft_str_isalnum_lem(line)))
			return (1);
		i++;
	}
	return (0);
}

int		chr_room(char *line)
{
	int i;
	int j;
	char **str;

	j = 1;
	i = 0;
	str = ft_strsplit(line, ' ');
	if (*str[0] == '\t')
		ft_exit("Error: Tabulation");
	while (str[j] != NULL && str[i] != NULL)
	{
		if (ft_str_isdigit(str[j]) && j != 2)
		{
			if (ft_str_isdigit(str[2]))
				j++;
		}
		i++;
	}
	free(str);
	if (i == 3 && j == 2)
		return (1);
	else
		return (0);
}
