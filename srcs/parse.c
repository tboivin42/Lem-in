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


t_path	*save_path(t_room *room)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new->name = room->name;
	new->start = (room->start == 1) ? 1 : 0;
	new->end = (room->end == 1) ? : 0;
	new->next = NULL;
	return (new);
}

void	add_back_path(t_path **path, t_room *room)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = save_path(room);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = save_path(room);
}

void	print_nb_ants(t_path *path, int i)
{
	ft_printf("L%d-%s\n", i, path->name);
}

void	print_ants(t_lem *lem, t_path *path)
{
	static int i;
	int j;
	t_path *begin;

	begin = path;
	if (!i)
	{
		i = 1;
		ft_printf("\n");
	}
	while (path)
	{
		j = i;
		ft_printf("L%d-%s\n", i, path->name);
		while (j != 0)
		{
			
		}
		// print_nb_ants(path, i);
		path = path->next;
	}
	path = begin;
	i++;
	if (i <= lem->ants)
	{
		ft_putchar('\n');
		print_ants(lem, path);
	}
}

void	stock_path(t_lem *lem, t_room *room)
{
	t_path *path;

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
			ft_error(line, 0);
			add_room(&room, line, 0);
		}
		else
			ft_exit("Parse: Error: T'as rien a foutre la toi !");
	}
	if (lem->start_tube == 0)
		ft_exit("Error: No links");
	reso(room);
	stock_path(lem, room);
}
