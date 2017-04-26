/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:03:20 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/18 22:03:22 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	path3(t_room **room, char *line, t_lem *lem)
{
	if (chr_room(line) == 1)
	{
		ft_error2(line, 0);
		add_room(room, line, 0);
	}
	else if (chr_tube(lem, line) == 0)
		ft_error();
}

void	path2(t_room **room, char *line, t_lem *lem, int i)
{
	while (ft_strcmp(line, "##start") == 0)
	{
		if (i == 0)
			add_room(room, line, 0);
		i++;
		get_next_line(0, &line);
		if (chr_room(line) == 1 && lem->pass2 == 0)
		{
			lem->pass2 = 1;
			ft_error2(line, 1);
			add_room(room, line, 1);
		}
		else
			add_room(room, line, 0);
	}
}

void	path(t_room **room, char *line, t_lem *lem)
{
	while (*line == '#')
	{
		lem->l = 0;
		while (ft_strcmp(line, "##end") == 0)
		{
			if (lem->l == 0)
				add_room(room, line, 0);
			lem->l++;
			get_next_line(0, &line);
			if (chr_room(line) == 1 && lem->pass == 0)
			{
				lem->pass = 1;
				ft_error2(line, 2);
				add_room(room, line, 2);
			}
			else if (chr_tube(lem, line) == 0 && chr_room(line) == 0)
				ft_error();
			else
				add_room(room, line, 0);
		}
		path2(room, line, lem, lem->l);
		get_next_line(0, &line);
	}
	path3(room, line, lem);
}

void	parse(char *line, t_lem *lem)
{
	t_room	*room;
	t_tube	*tube;

	room = NULL;
	tube = NULL;
	while (get_next_line(0, &line))
	{
		if (*line == '#')
			path(&room, line, lem);
		else if (ft_strchr(line, '-') && chr_tube(lem, line) == 1)
			add_tube(&tube, line);
		else if (chr_room(line) == 1)
		{
			ft_error2(line, 0);
			add_room(&room, line, 0);
		}
		else
			ft_error();
	}
	error(room, tube, lem);
	// print_anthill(tube, room, lem);
}
