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

void	test(t_room *room)
{
	// ft_printf("sakjfje\n");
	while (room)
	{
		ft_printf("[%s]\n", room->name);
		if (room->start == 1)
			ft_printf("--%d--\n", room->path);
		room = room->next;
	}
}

void reso_(t_room *room)
{
	while (room)
	{
		if (room->start == 1)
		{
			room->path = 1;
		}
		room = room->next;
	}
}

void	reso(t_room *room)
{
	reso_(room);
	test(room);
}
