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

t_lem	*set_struct()
{
	t_lem *lem;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		return (NULL);
	lem->ants = 0;
	lem->l = 0;
	lem->pass = 0;
	lem->pass2 = 0;
	lem->start = NULL;
	lem->end = NULL;
	return (lem);
}

int		main(void)
{
	char	*line;
	t_lem	*lem;

	lem = set_struct();
	if (get_next_line(0, &line) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	lem->ants = ft_atoi(line);
	if (lem->ants <= 0 || lem->ants >= 2147483647)
	{
		ft_printf("Error: No ants MTF\n");
		exit(1);
	}
	parse(line, lem);
	free(lem);
	while (1)
		;
	return (0);
}