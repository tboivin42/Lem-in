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

#include "../includes/lem-in.h"

t_tube	*create_tube(char *name, t_tube *tube)
{
	t_tube *new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	new->name = name;
	new->next = tube;
	return (new);
}

t_room	*create_room(char *line, int start)
{
	t_room *new;
 
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	new->name = line;
	new->start = start;
	new->next = NULL;
	return (new);
}

void	add_room(t_room **new, char *line, int start)
{
	t_room *tmp;

	tmp = (*new);
	if (!(*new))
	{
		(*new) = create_room(line, start);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_room(line, start);
}

void	add_tube(t_tube **new, char *line, t_lem *lem, t_room *room)
{
	t_tube 	*tmp;
	char 	**s;
	int i;

	i = 0;
	lem->start_tube = 1;
	tmp = (*new);
	s = ft_strsplit(line, '-');
	error(room, lem, s);
	if (search_way(s, room) == 0)
		ft_exit("Error: No way");
	// if (!(*new))
	// {
	// 	while (room)
	// 	{
	// 		if (room->start == 1)
	// 			break ;
	// 		room = room->next;
	// 	}
	// 	(*new) = create_tube(room->name, NULL);
	// }
	// while (*new)
	// {
	// 	ft_printf("%s\n", (*new)->name);
	// 	*new = (*new)->next;
	// }
	// while (tmp->next)
	// 	tmp = tmp->next;
	// tmp->next = create_tube(room);
	// exit(1);
}
