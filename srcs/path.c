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

void	if_end(t_room *room, t_room *tmp, t_lem *lem)
{
	while (tmp)
	{
		if (tmp->end == 1)
		{
			if (!ft_strcmp(room->name, tmp->name))
			{
				lem->tamere = 1;
				ft_printf("%s\n", room->name);
				return ;
			}
		}
		tmp = tmp->next;
	}
	room->path = 2;
}

void	reso_(t_room *room, t_room *tmp, t_lem *lem)
{
	(void)tmp;
	while (room->tube)
	{
		room->path = 1;
		if (room->tube->room->path == 0)
			room = room->tube->room;
		else
			room->tube = room->tube->next;
	}
	if_end(room, tmp, lem);
}

void	reso(t_lem *lem, t_room *room)
{
	t_room *tmp;
	int i;

	i = 0;
	tmp = room;
	while (room && room->start != 1)
		room = room->next;
	while (room->tube)
	{
		reso_(room, tmp, lem);
		if (lem->tamere == 1)
			break ;
		else
			room->tube = room->tube->next;
	}
}
