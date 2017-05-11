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

#include "../includes/lem-in.h"

void	path3(t_room **room, char *line, t_lem *lem)
{
	if (chr_room(line, *room) == 1)
	{
		ft_error(line, 0);
		add_room(room, line, 0);
	}
	else if (chr_room(line, *room) == 0 && ft_strchr(line, '-'))
		add_tube(line, lem, *room);
	else
		ft_exit("Path3: Error: T'as rien a foutre la toi !");
}

void	path2(t_room **room, char *line, t_lem *lem)
{
	
	while (ft_strcmp(line, "##start") == 0)
	{
		while (ft_strcmp(line, "##end") != 0 && *line == '#')
			get_next_line(0, &line);
		if (chr_room(line, *room) == 1 && lem->pass2 == 0)
		{
			lem->pass2 = 1;
			ft_error(line, 1);
			add_room(room, line, 1);
		}
		else if ((*line != '#' && chr_room(line, *room) == 0))
			ft_exit("Path2: Error: T'as rien a foutre la toi !");
	}
}

void	path(t_room **room, char *line, t_lem *lem)
{
	while (*line == '#')
	{
		while (ft_strcmp(line, "##end") == 0)
		{
			while (ft_strcmp(line, "##start") != 0 && *line == '#')
				get_next_line(0, &line);
			if (chr_room(line, *room) == 1 && lem->pass == 0)
			{
				lem->pass = 1;
				ft_error(line, 2);
				add_room(room, line, 2);
			}
			else if ((*line != '#' && chr_room(line, *room) == 0))
				ft_exit("Path: Error: T'as rien a foutre la toi !");
		}
		path2(room, line, lem);
		get_next_line(0, &line);
	}
	if (*line)
		path3(room, line, lem);
}

void	print_nb_ants(t_room *room, int i)
{
	ft_printf("L%d-%s\n", i, room->name);
}

void	print_ants(t_lem *lem, t_room *room)
{
	int i;

	i = 1;
	ft_printf("\n");
	lem->ants = lem->ants;
	while (room && room->start != 1)
		room = room->next;
	while (room->tube->room->path == 1)
	{
		room = room->tube->room;
		print_nb_ants(room, i);
		if (room->end == 1)
			break ;
	}
}

void	print_room(t_room *room)
{
	ft_putendl("");
	while (room)
	{
		ft_printf("[%s] {%d}\n", room->name, room->path);
		while (room->tube)
			room->tube = room->tube->next;
		room = room->next;
	}
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
		{
			path(&room, line, lem);
		}
		else if (*line && ft_strchr(line, '-'))
			add_tube(line, lem, room);
		else if (*line && chr_room(line, room) == 1)
		{
			if (lem->start_tube == 1)
				break ;
			ft_error(line, 0);
			add_room(&room, line, 0);
		}
		else
			ft_exit("Parse: Error: T'as rien a foutre la toi !");
	}
	exit(0);
	if (lem->start_tube == 0)
		ft_exit("Error: No links");
	ft_putendl("");
	reso(room);
	// print_room(room);
	print_ants(lem, room);
}
