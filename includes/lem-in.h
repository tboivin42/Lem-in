/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:10:21 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/08 02:10:25 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
#include "../libft/includes/libft.h"



typedef struct  		s_room
{
	char 				*line;
	int					end;
	int					start;
	struct s_room		*next;
}						t_room;

typedef struct 			s_tube
{
	t_room				*room;
	char				*line;
	struct s_tube		*next;
}						t_tube;

typedef	struct			s_lem
{
	int 				l;
	int					pass;
	int					pass2;
	int					ants;
	char				*start;
	char				*end;
}						t_lem;

void					ft_error2(char *line, int u);
void					check_room(t_room *room);
void					ft_error(void);
int 					chr_tube(t_lem *lem, char *line);
int						chr_room(char *line);
void					print_anthill(t_tube *tube, t_room *room, t_lem *lem);
void					error(t_room *room, t_tube *tube, t_lem *lem);
void					parse(char *line, t_lem *lem);
void					add_room(t_room **new, char *line, int start);
void					add_tube(t_tube **new, char *line);

#endif