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
	ft_printf("%d\n", lem->ants);
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
	{
		ft_printf("Error: Fallait pas mettre de 'L' ou de '#' aujourd'hui\n");
		exit(1);
	}
	else if (u == 1 && (*line == 'L' || *line == '#'))
	{
		ft_printf("Error: C'est pas la bonne entree\n");
		exit(1);
	}
	else if (u == 2 && (*line == 'L' || *line == '#'))
	{
		ft_printf("Error: C'est pas la bonne sortie\n");
		exit(1);
	}
}

void	error(t_room *room, t_tube *tube, t_lem *lem)
{
	check_room(room);
	if (lem->pass == 0)
	{
		ft_printf("Error: Ca n'en finit donc jamais ? #marvel\n");
		exit(1);
	}
	if (lem->pass2 == 0)
	{
		ft_printf("Error: Pas de ligne d'arriver ou en retard comme le lapin ?\n");
		exit(1);
	}
	if (!tube)
	{
		ft_printf("Error: Mario a voler tout les tubes ?\n");
		exit (1);
	}
}