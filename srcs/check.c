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

#include "../includes/lemin.h"

void	check__(t_room **room, char *line, t_lem *lem)
{
	if (src_room(line, *room) == 1)
		add_room(room, line, 0);
	else if (src_room(line, *room) == 0 && ft_strchr(line, '-'))
		add_tube(line, lem, *room);
	else
		ft_exit("Path3: Error: False Room !");
}

void	check_(t_room **room, char *line, t_lem *lem)
{
	while (ft_strcmp(line, "##start") == 0)
	{
		while (ft_strcmp(line, "##end") != 0 && *line == '#')
		{
			if_froom(line);
			get_next_line(0, &line);
		}
		if (src_room(line, *room) == 1 && lem->pass2 == 0)
		{
			lem->pass2 = 1;
			add_room(room, line, 1);
			free(line);
		}
		else if ((*line != '#' && src_room(line, *room) == 0))
			ft_exit("Path2: Error: False Room !");
	}
	if (*line == 'L' || *line == '#')
		if_froom(line);
}

void	check(t_room **room, char *line, t_lem *lem)
{
	while (*line == '#')
	{
		while (ft_strcmp(line, "##end") == 0)
		{
			while (ft_strcmp(line, "##start") != 0 && *line == '#')
			{
				if_froom(line);
				get_next_line(0, &line);
			}
			if (src_room(line, *room) == 1 && lem->pass == 0)
			{
				lem->pass = 1;
				add_room(room, line, 2);
				free(line);
			}
			else if ((*line != '#' && src_room(line, *room) == 0))
				ft_exit("Path: Error: False Room !");
		}
		check_(room, line, lem);
		get_next_line(0, &line);
	}
	if (*line)
		check__(room, line, lem);
}

int		check_if_same(t_room *room, char *room1)
{
	while (room)
	{
		if (!ft_strcmp(room->name, room1))
			return (1);
		room = room->next;
	}
	return (0);
}

int		src_room(char *line, t_room *room)
{
	int		i;
	int		j;
	char	**str;

	j = 1;
	i = 0;
	str = ft_strsplit(line, ' ');
	if (!str[2])
		return (0);
	if (room && check_if_same(room, str[0]))
		ft_exit("Error: Room already declared");
	while (str[j] != NULL && str[i] != NULL)
	{
		if (ft_str_isdigit(str[j]) && j != 2)
		{
			if (ft_str_isdigit(str[2]))
				j++;
		}
		i++;
	}
	i = (i == 3 && j == 2) ? 1 : 0;
	free_split(str);
	return (i);
}
