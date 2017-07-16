/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:12:41 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:53:40 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validate_spaces(char *line)
{
	int spaces;
	int x;

	spaces = 0;
	x = -1;
	while (line[++x])
	{
		if (line[x] == ' ')
			spaces++;
	}
	return (spaces);
}

int		check_for_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((validate_spaces(line)) == 2)
		return (1);
	return (0);
}

int		get_rooms(t_lame *llama, char *line)
{
	if (!check_for_room(line))
		return (0);
	add_room(llama, line);
	llama->room_count++;
	return (1);
}

int		get_start_end(t_lame *llama, char *line)
{
	if ((ft_strcmp(line, "##start")) == 0)
	{
		llama->start_on = 1;
		return (1);
	}
	else if ((ft_strcmp(line, "##end")) == 0)
	{
		llama->end_on = 1;
		return (1);
	}
	return (0);
}

int		get_input(t_lame *llama)
{
	int		count;
	char	*line;

	count = 0;
	llama->raw = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		if (get_ants(llama, line))
			;
		else if (get_rooms(llama, line))
			;
		else if (get_links(llama, line))
			;
		else if (get_start_end(llama, line))
			;
		llama->raw = ft_strxjoin(llama->raw, line, 1);
		llama->raw = ft_strxjoin(llama->raw, "\n", 1);
		free(line);
		count++;
	}
	add_doors_to_rooms(llama);
	if (!validate_input(llama))
		return (0);
	return (1);
}
