/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:49:19 by tboivin           #+#    #+#             */
/*   Updated: 2017/05/05 12:49:20 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	src_path_(t_room **room, t_room **tmp, t_room *tmp2, t_room *begin)
{
	(*room)->path = 2;
	while (*tmp)
	{
		if ((*tmp)->path == 1)
			(*tmp)->path = 0;
		*tmp = (*tmp)->next;
	}
	*tmp = tmp2;
	*room = begin;
}

void	stop_(t_room *begin)
{
	while (begin)
	{
		if (begin->path == 0)
			return ;
		begin = begin->next;
	}
	ft_exit("Error: No links to the end");
}

void	src_path(t_room *room, t_room *begin, t_room *tmp)
{
	t_room *tmp2;

	tmp2 = tmp;
	while (room && (room->end != 1))
	{
		(!begin->tube) ? ft_exit("Error: No links") : stop_(begin->tube->room);
		if (room->tube)
		{
			if (room->tube->room->path == 0)
			{
				room->path = 1;
				room = room->tube->room;
			}
			else
			{
				while (room->tube && room->tube->room->path != 0)
					room->tube = room->tube->next;
				if (!room->tube)
					src_path_(&room, &tmp, tmp2, begin);
			}
		}
	}
	if (room->end == 1)
		room->path = 1;
}

void	reso(t_room *room)
{
	t_room	*tmp;
	t_room	*begin;

	tmp = room;
	while (room && room->start != 1)
		room = room->next;
	begin = room;
	room->path = 2;
	src_path(room, begin, tmp);
}
