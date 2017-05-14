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

t_path	*save_path(t_room *room, t_lem *lem)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new->name = room->name;
	new->start = (room->start == 1) ? 1 : 0;
	new->end = (room->end == 1) ? : 0;
	new->ants = (new->start == 1) ? lem->ants : 0;
	new->next = NULL;
	return (new);
}

char	*get_last_name(t_path *path)
{
	while (path->next)
		path = path->next;
	return (path->name);
}
void	add_back_path(t_path **path, t_room *room, t_lem *lem)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = save_path(room, lem);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = save_path(room, lem);
}

int			count_list_(t_path *path)
{
	int i;

	i = 0;
	while (path)
	{
		i++;
		path = path->next;
	}
	return (i);
}

t_path		*count_list(t_path *path, int index)
{
	int i;

	i = 1;
	while (i != index)
	{
		i++;
		path = path->next;
	}
	return (path);
}

void	print_a(t_lem *lem, t_path *path)
{
	path = count_list(path, lem->j);
	// if (!ft_strcmp(path->name, lem->end))
	// 	lem->i++;
	if(lem->ant <= lem->ants)
		ft_printf("L%d-%s ", lem->ant, path->name);
}


void	print_ants(t_lem *lem, t_path *path)
{
	static int ok;
	int end;

	ok = 1;
	end = 0;
	lem->i = 1;
	lem->ant = 1;
	lem->end = count_list_(path);
	while (1)
	{
		if (end == lem->ants)
			break;
		lem->j = lem->i;
		while (lem->j > 0)
		{
			print_a(lem, path);
			lem->j--;
			lem->ant++;
		}
		if (lem->i == lem->end)
		{
			end++;
			ok++;
		}
		else 
			lem->i++;
		lem->ant = ok;
		ft_putchar('\n');
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
		add_back_path(&path, room, lem);
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
