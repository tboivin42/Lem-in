/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:10:21 by tboivin           #+#    #+#             */
/*   Updated: 2017/04/08 02:10:25 by tboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/includes/libft.h"

typedef struct			s_path
{
	char				*name;
	struct s_path		*next;
}						t_path;

typedef struct			s_room
{
	char				*name;
	int					end;
	int					path;
	int					room;
	int					start;
	struct s_tube		*tube;
	struct s_room		*next;
}						t_room;

typedef struct			s_tube
{
	t_room				*room;
	struct s_tube		*next;
	struct s_tube		*prev;
}						t_tube;

typedef	struct			s_lem
{
	int					start_tube;
	int					ant;
	int					i;
	int					j;
	int					pass;
	int					pass2;
	int					end;
	long long			ants;
}						t_lem;

/*
**						Parse.c
*/
void					parse(char *line, t_lem *lem);

/*
**						Add_lists.c
*/
void					add_room(t_room **new, char *line, int start);
void					add_tube(char *line, t_lem *lem, t_room *room);

/*
**						Check.c
*/
int						src_room(char *line, t_room *room);
void					check(t_room **room, char *line, t_lem *lem);

/*
**					Path.c
*/
void					reso(t_room *room);

/*
**					Print.c
*/
void					print_ants(t_lem *lem, t_path *path);
/*
**					Tool.c
*/
int						search_way(char **s, t_room *room);
int						check_line(char *line);
t_tube					*create_tube(t_room *room);
void					error(t_lem *lem, char **s);
/*
**					Tool2.c
*/
void					free_list(t_path **path);
void					add_back_path(t_path **path, t_room *room);
t_path					*list_until(t_path *path, int index);
int						count_list(t_path *path);

/*
**					Tool3.c
*/
void					if_froom(char *line);
void					free_split(char **str);

#endif
