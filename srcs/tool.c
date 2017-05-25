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

#include "../includes/lemin.h"

int		check_line(char *line)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	return (j == 1);
}

t_tube	*create_tube(t_room *room)
{
	t_tube *new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		ft_exit("Error: Failed to malloc");
	new->room = room;
	new->next = NULL;
	return (new);
}

void	error(t_lem *lem, char **s)
{
	if (lem->pass == 0)
		ft_exit("Error: Ca n'en finit donc jamais ? #marvel");
	if (lem->pass2 == 0)
		ft_exit("Error: Je suis parti en pause");
	if (!s)
		ft_exit("Error: Mario a voler tout les tubes");
	if (!s[0] || !s[1] || s[2])
		ft_exit("Error: Not a tube");
}

int		search_way(char **s, t_room *room)
{
	int		i;
	t_room	*tmp;

	tmp = room;
	i = 0;
	while (tmp)
	{
		if (ft_strcccmp(tmp->name, s[0], ' ') == 0)
		{
			i++;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = room;
	while (tmp)
	{
		if (ft_strcccmp(tmp->name, s[1], ' ') == 0)
		{
			i++;
			break ;
		}
		tmp = tmp->next;
	}
	return (i == 2);
}
