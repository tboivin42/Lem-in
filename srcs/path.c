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

#include "../includes/lem-in.h"

void algo_(t_room *room, t_room *begin, t_room *tmp)
{
	t_room *tmp2;

	tmp2 = tmp;
	while(room && (room->end != 1))
	{
		if (room->tube)
		{
			if (room->tube->room->path == 0)
			{
				room->path = 1;
				room = room->tube->room;
			}
			else
			{
				while(room->tube && room->tube->room->path != 0)
					room->tube = room->tube->next;
				if (!room->tube)
				{
					room->path = 2;
					while (tmp)
					{
						if (tmp->path == 1)
							tmp->path = 0;
						tmp = tmp->next;
					}
					tmp = tmp2;
					room = begin;
				}
			}
		}
		ft_printf("[%s - %d]\n",room->name, room->path);
	}
}

void	reso(t_lem *lem, t_room *room)
{
	t_room *tmp;
	t_room *begin;
	int i;

	i = 0;
	tmp = room;
	while (room && room->start != 1)
		room = room->next;
	begin = room;
	room->path = 0;	
	algo_(room, begin, tmp);
}
