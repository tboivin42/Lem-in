/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 03:44:57 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/09 03:45:00 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room	*create_room(char *line, int start)
{
	t_room *new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		ft_exit("Error: Failed to malloc");
	new->name = ft_strsub(line, 0, ft_strclen(line, ' '));
	new->room = (start == 0) ? 1 : 0;
	new->start = (start == 1) ? 1 : 0;
	new->end = (start == 2) ? 1 : 0;
	new->path = 0;
	new->tube = NULL;
	new->next = NULL;
	return (new);
}

void	add_room(t_room **new, char *line, int start)
{
	t_room *tmp;

	tmp = (*new);
	if (*line == '#' || *line == 'L')
		ft_exit("Error");
	if (!(*new))
	{
		(*new) = create_room(line, start);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_room(line, start);
}

void	add_back_tube(t_tube **new, t_room *room)
{
	t_tube *tmp;

	tmp = (*new);
	if (!(*new))
	{
		(*new) = create_tube(room);
		(*new)->prev = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_tube(room);
	tmp->next->prev = tmp;
}

void	add_second_tube(t_room *full, char *s, t_room *room)
{
	while (full)
	{
		if (!ft_strcmp(full->name, s))
		{
			add_back_tube(&full->tube, room);
			add_back_tube(&room->tube, full);
		}
		full = full->next;
	}
}

void	add_tube(char *line, t_lem *lem, t_room *room)
{
	t_room	*tmp;
	char	**s;
	int		i;

	i = 0;
	tmp = room;
	s = NULL;
	lem->start_tube = 1;
	if (check_line(line) == 1)
		s = ft_strsplit(line, '-');
	else
		ft_exit("Error: False tube");
	error(lem, s);
	if (search_way(s, room) == 0)
		ft_exit("Error: No way");
	while (room)
	{
		if (!ft_strcmp(room->name, s[0]))
			add_second_tube(tmp, s[1], room);
		room = room->next;
	}
	if (s)
		free_split(s);
}
