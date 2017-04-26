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
					ft_strcmp(room->line, tmp->next->line) == 0)
				{
					ft_printf("[%s] [%s]\n", tmp->next->line, room->line);
					ft_printf("C'est faux ARCHIFAUX");
					exit(1);
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
		if (line[i] == '-' && (ft_isalnum(line[i + 1]))
			&& ft_isalnum(line[i - 1]))
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
	while (str[j] != NULL && str[i] != NULL)
	{
		if (ft_isdigit(str[j][0]) && j != 2)
		{
			if (ft_isdigit(str[2][0]))
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
