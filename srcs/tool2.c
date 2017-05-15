/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:33:55 by tboivin           #+#    #+#             */
/*   Updated: 2017/05/14 18:33:56 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_list(t_path **path)
{
	t_path *tmp;

	while (*path)
	{
		tmp = *path;
		*path = (*path)->next;
		free(tmp->name);
		free(tmp);
	}
	free(*path);
}

t_path	*save_path(t_room *room)
{
	t_path *new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->name = room->name;
	new->next = NULL;
	return (new);
}

void	add_back_path(t_path **path, t_room *room)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = save_path(room);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = save_path(room);
}

t_path	*list_until(t_path *path, int index)
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

int		count_list(t_path *path)
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
