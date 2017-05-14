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

t_tube	*create_tube(t_room *room)
{
	t_tube *new;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (NULL);
	new->room = room;
	new->next = NULL;
	return (new);
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





	// static int i;
	// int j;
	// int t;
	// static int k;
	// t_path *begin;

	// begin = path;
	// if (!k)
	// 	k = 1;
	// j = lem->ants;
	// if (!i)
	// {
	// 	i = 1;
	// 	ft_printf("L%d-%s\n", i, path->name);
	// }
	// else
	// {
	// 	while (i <= lem->ants)
	// 	{
	// 		while (path)
	// 		{
	// 			if (path->next)
	// 			{
	// 				if (t == 1)
	// 					ft_printf("L%d-%s ", i, path->next->name);
	// 				else
	// 				{
	// 					if (i - 1 == 0)
	// 						ft_printf("L%d-%s ", i - 1, path->next->name);
	// 					else
	// 						ft_printf("L%d-%s ", i, path->next->name)
	// 					t = 1;
	// 				}
	// 			}
	// 			ft_printf("L%d-%s\n", i, path->name);
	// 			path = path->next;
	// 		}
	// 		path = begin;
	// 		i++;
	// 	}
	// }
	// i = 1;
	// // i++;
	// // ft_putchar('\n');
	// if (k <= lem->ants)
	// {
	// 	k++;
	// 	print_ants(lem, path);
	// }