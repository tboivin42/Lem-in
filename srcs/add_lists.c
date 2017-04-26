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

t_tube	*create_tube(char *line)
{
	t_tube *new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

t_room	*create_room(char *line, int start)
{
	t_room *new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	ft_printf("%s\n", line);
	new->line = line;
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

void	add_tube(t_tube **new, char *line)
{
	t_tube *tmp;

	tmp = (*new);
	if (!(*new))
	{
		(*new) = create_tube(line);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_tube(line);
}