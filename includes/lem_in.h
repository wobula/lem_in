/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:46:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 10:34:31 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <inttypes.h>

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				door_count;
	char			**door_names;
	struct s_room	*next;
	struct s_room	*solution;
	struct s_room	*prev;
	int				checked;
	int				path;
	int				pos;
	int				ant_count;
}					t_room;

typedef struct		s_lemk
{
	char			*r1;
	char			*r2;
	struct s_lemk	*next;
}					t_lemk;

typedef struct		s_lame
{
	int				ant_count;
	int				room_count;
	int				link_count;
	int				start_on;
	int				end_on;
	struct s_room	*rooms;
	struct s_lemk	*links;
	struct s_room	*solution;
	int				mode;
	int				x;
	struct s_room	*tmp;
	char			*raw;
}					t_lame;

int					check_for_end(t_lame *llama, char *door_name, int y);
void				free_all(t_lame *llama);
int					validate_input(t_lame *llama);
void				solve(t_lame *llama);
void				add_doors_to_rooms(t_lame *llama);
void				create_solution_path(t_lame *llama, t_room *rooms);
int					get_input(t_lame *llama);
void				add_room(t_lame *llama, char *line);
int					get_links(t_lame *llama, char *line);
void				display_room_links(t_lame *llama);
int					part_of_path(t_room *tmp, int y);
int					end_room(t_lame *llama, t_room *tmp, int y);
int					get_ants(t_lame *llama, char *line);
int					check_ants(char *str);
int					display_rooms(t_lame *llama);
int					validate_path(t_lame *llama, t_room *rooms);
t_room				*get_origin(t_room *room);

#endif
