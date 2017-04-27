/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 00:27:03 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/19 00:27:05 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	print_anthill(t_tube *tube, t_room *room, t_lem *lem)
{	
	ft_printf("\n%d\n", lem->ants);
	while (room)
	{
		if (room->start == 1)
			ft_printf("[%s]\n", room->line);
		else if (room->start == 2)
			ft_printf("[%s]\n", room->line);
		else
			ft_printf("%s\n", room->line);
		room = room->next;
	}
	while (tube)
	{
		ft_printf("%s\n", tube->line);
		tube = tube->next;
	}
}

void	ft_error(char *line, int u)
{
	if (u == 0 && (line[0] == 'L' || line[0] == '#'))
		ft_exit("Error: Fallait pas mettre de 'L' ou de '#' aujourd'hui");
	else if (u == 1 && (*line == 'L' || *line == '#'))
		ft_exit("Error: C'est pas la bonne entree");
	else if (u == 2 && (*line == 'L' || *line == '#'))
		ft_exit("Error: C'est pas la bonne sortie");
}

void	error(t_room *room, t_tube *tube)
{
	(void)tube;
	check_room(room);
	if (!tube)
		ft_exit("Error: Mario a voler tout les tubes ?");
}