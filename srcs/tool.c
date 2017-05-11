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

void	ft_error(char *line, int u)
{
	if (u == 0 && (line[0] == 'L' || line[0] == '#'))
		ft_exit("Error: Fallait pas mettre de 'L' ou de '#' aujourd'hui");
	else if (u == 1 && (*line == 'L' || *line == '#'))
		ft_exit("Error: C'est pas la bonne entree");
	else if (u == 2 && (*line == 'L' || *line == '#'))
		ft_exit("Error: C'est pas la bonne sortie");
}

void	error(t_room *room, t_lem *lem, char **s)
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
	int i;
	t_room *tmp;

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
