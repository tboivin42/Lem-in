/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 00:50:12 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/08 00:50:14 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_lem	*set_struct(char *line)
{
	t_lem *lem;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	lem->start_tube = 0;
	lem->ants = ft_atoi(line);
	lem->l = 0;
	lem->i = 0;
	lem->j = 0;
	lem->ant = 0;
	lem->pass = 0;
	lem->tamere = 0;
	lem->pass2 = 0;
	lem->start = NULL;
	lem->end = 0;
	return (lem);
}

int		main(void)
{
	char	*line;
	int		i;
	t_lem	*lem;

	if (get_next_line(0, &line) == -1)
		ft_exit("Error: Not good files");
	while (*line == '#' && ft_strcmp(line, "##start") != 0
		&& ft_strcmp(line, "##end") != 0)
		get_next_line(0, &line);
	lem = set_struct(line);
	i = ft_power(lem->ants);
	if (lem->ants <= 0 || lem->ants >= 2147483647 || i > 10 
		|| *line == '-')
		ft_exit("Error: False ants");
	parse(line, lem);
	return (0);
}
