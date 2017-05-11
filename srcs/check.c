/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 03:48:40 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/26 03:48:42 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

// void	check_room(t_room *room)
// {
// 	t_room *tmp;
// 	size_t ok;
// 	size_t ok1;

// 	ok = 0;
// 	ok1 = 0;

// 	while (room->next)
// 	{
// 		tmp = room;
// 		while (tmp)
// 		{
// 			if (tmp->next)
// 			{
// 				if (*room->name != '#' && *tmp->next->name != '#' &&
// 					ft_strccmp(room->name, tmp->next->name, ' ') == 0)
// 				{
// 					ft_printf("[%s] [%s]\n", tmp->next->name, room->name);
// 					ft_exit("Error: Identical room");
// 				}
// 			}
// 			ok++;
// 			tmp = tmp->next;
// 		}
// 		ok1++;
// 		room = room->next;
// 	}
// 	ok += ok1;
// 	ft_putnbr(ok);
// 	exit(0);
// }

/* **	FONCTION A PEUT-ETRE SUPPRIMER **
int 	chr_tube(t_lem *lem, char *line)
{
	int i;

	(void)lem;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-' && (ft_str_isascii(line)))
			return (1);
		i++;
	}
	return (0);
}
** */

int checkIfSame(t_room *room, char *newRoom)
{
	while (room)
	{
		if (!ft_strcmp(room->name, newRoom))
			return (1);
		room = room->next;
	}
	return (0);
}

int		chr_room(char *line, t_room *room)
{
	int i;
	int j;
	char **str;

	j = 1;
	i = 0;
	str = ft_strsplit(line, ' ');
	if (*str[0] == '\t')
		ft_exit("Error: Tabulation");
	if (!str[2])
		return(0);
	if (room && checkIfSame(room, str[0]))
		ft_exit("Room already declared");
	while (str[j] != NULL && str[i] != NULL)
	{
		if (ft_str_isdigit(str[j]) && j != 2)
		{
			if (ft_str_isdigit(str[2]))
				j++;
		}
		i++;
	}
	free(str);
	if (i == 3 && j == 2)
		return (1);
	else
		return (0);
}
