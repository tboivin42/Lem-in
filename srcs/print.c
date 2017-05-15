/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:04:02 by tboivin           #+#    #+#             */
/*   Updated: 2017/05/14 18:04:28 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	color(void)
{
	static int	i;
	char		**color;

	if (!(color = (char**)malloc(sizeof(char*) * 9)))
		return ;
	if (!i)
		i = 0;
	color[0] = "\x1B[31m";
	color[1] = "\x1B[32m";
	color[2] = "\x1B[33m";
	color[3] = "\x1B[34m";
	color[4] = "\x1B[35m";
	color[5] = "\x1B[36m";
	color[6] = "\x1B[38m";
	color[7] = "\x1B[39m";
	color[8] = "\x1B[40m";
	color[9] = "\x1B[41m";
	ft_putstr(color[i]);
	i++;
	if (i == 9)
		i = 0;
}

void	print_a(t_lem *lem, t_path *path)
{
	path = list_until(path, lem->j);
	if (lem->ant <= lem->ants)
	{
		color();
		ft_printf("L%d-%s ", lem->ant, path->name);
	}
}

void	print_ants_(t_lem *lem, t_path *path)
{
	while (lem->j > 0)
	{
		print_a(lem, path);
		lem->j--;
		lem->ant++;
	}
}

void	what_print(t_lem *lem, t_path *path)
{
	ft_printf("\n\nThe ants will go through %d rooms:\n", lem->end);
	while (path->next)
	{
		ft_printf("%s->", path->name);
		path = path->next;
	}
	ft_printf("%s\n\n", path->name);
}

void	print_ants(t_lem *lem, t_path *path)
{
	static int	ant;
	int			end;

	ant = 1;
	end = 0;
	lem->i = 1;
	lem->ant = 1;
	lem->end = count_list(path);
	what_print(lem, path);
	while (1)
	{
		if (end == lem->ants)
			break ;
		lem->j = lem->i;
		print_ants_(lem, path);
		if (lem->i == lem->end)
		{
			end++;
			ant++;
		}
		else
			lem->i++;
		ft_putchar('\n');
		lem->ant = ant;
	}
}
