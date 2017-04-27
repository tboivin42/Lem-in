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

void	path3(t_room **room, char *line, t_lem *lem, t_tube **tube)
{
	if (chr_room(line) == 1)
	{
		ft_error(line, 0);
		add_room(room, line, 0);
	}
	if (chr_tube(lem, line) == 1)
		add_tube(tube, line, lem);
	else if (chr_tube(lem, line) == 0 && chr_room(line) == 0)
		ft_exit("Path3: Error: T'as rien a foutre la toi !");
}

void	path2(t_room **room, char *line, t_lem *lem)
{
	while (ft_strcmp(line, "##start") == 0)
	{
		while (ft_strcmp(line, "##end") != 0 && *line == '#')
			get_next_line(0, &line);
		if (chr_room(line) == 1 && lem->pass2 == 0)
		{
			lem->pass2 = 1;
			ft_error(line, 1);
			add_room(room, line, 1);
		}
		else if ((*line != '#' && chr_room(line) == 0) ||
		 chr_tube(lem, line) == 1)
			ft_exit("Path2: Error: T'as rien a foutre la toi !");
	}
}

void	path(t_room **room, char *line, t_lem *lem, t_tube **tube)
{
	while (*line == '#')
	{
		while (ft_strcmp(line, "##end") == 0)
		{
			while (ft_strcmp(line, "##start") != 0 && *line == '#')
				get_next_line(0, &line);
			if (chr_room(line) == 1 && lem->pass == 0)
			{
				lem->pass = 1;
				ft_error(line, 2);
				add_room(room, line, 2);
			}
			else if ((*line != '#' && chr_room(line) == 0) ||
			 chr_tube(lem, line) == 1)
				ft_exit("Path: Error: T'as rien a foutre la toi !");
		}
		path2(room, line, lem);
		get_next_line(0, &line);
	}
	if (*line)
		path3(room, line, lem, tube);
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
			path(&room, line, lem, &tube);
		else if (*line && ft_strchr(line, '-') && 
			chr_tube(lem, line) == 1)
				add_tube(&tube, line, lem);
		else if (*line && chr_room(line) == 1)
		{
			if (lem->start_tube == 1)
				break ;
			ft_error(line, 0);
			add_room(&room, line, 0);
		}
		else
			ft_exit("Parse: Error: T'as rien a foutre la toi !");
	}
	error(room, tube);
	ft_putchar('\n');
	// while(room)
	// {
	// 	ft_printf("[%s]\n",room->line);
	// 	room = room->next;
	// }
	// print_anthill(tube, room, lem);
}
