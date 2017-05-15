/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:03:20 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/18 22:03:22 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	stock_path(t_lem *lem, t_room *room)
{
	t_path	*path;
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = room;
	path = NULL;
	while (room && room->start != 1)
		room = room->next;
	while (room->tube->room->path == 1)
	{
		room = room->tube->room;
		add_back_path(&path, room);
		if (room->end == 1)
			break ;
	}
	print_ants(lem, path);
	free_list(&path);
}

void	parse(char *line, t_lem *lem)
{
	t_room	*room;
	t_tube	*tube;

	room = NULL;
	tube = NULL;
	while (get_next_line(0, &line))
	{
		if (*line == '#')
			check(&room, line, lem);
		else if (*line && ft_strchr(line, '-'))
			add_tube(line, lem, room);
		else if (*line && src_room(line, room) == 1)
		{
			if (lem->start_tube == 1)
				break ;
			add_room(&room, line, 0);
		}
		else
			ft_exit("Parse: Error");
	}
	if (lem->start_tube == 0)
		ft_exit("Error: No links");
	reso(room);
	stock_path(lem, room);
}
