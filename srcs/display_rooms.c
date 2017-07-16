/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:23:48 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 10:23:51 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validate(t_lame *llama, t_room *tmp, int x, int y)
{
	if (llama->mode == 1)
		ft_printf("checking door %s in room: %s\n",
				tmp->door_names[x], tmp->name);
	if (check_for_end(llama, tmp->door_names[x], y))
	{
		if (llama->mode == 1)
			ft_printf("end found!\n");
		return (1);
	}
	return (0);
}

int		validate_path(t_lame *llama, t_room *rooms)
{
	t_room	*tmp;
	int		x;
	int		y;

	tmp = get_origin(rooms);
	y = 0;
	tmp->checked = 1;
	tmp->pos = y;
	tmp->path = 1;
	if (tmp->door_count == 0)
		return (0);
	if (llama->mode == 1)
		ft_printf("[.cyan.Search:.]\n");
	x = -1;
	while (tmp->door_names[++x])
	{
		if (validate(llama, tmp, x, y))
			return (1);
	}
	return (0);
}

int		error_msgs(t_lame *llama)
{
	if (llama->mode == 1)
		ft_printf("Start and end found\n");
	return (1);
}

int		display_rooms(t_lame *llama)
{
	int		count;
	int		start;
	int		end;
	t_room	*tmp;

	tmp = llama->rooms;
	count = 0;
	start = 0;
	end = 0;
	while (tmp)
	{
		if ((count = count + 1) && tmp->start == 1)
			start = 1;
		if (tmp->end == 1)
			end = 1;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
	{
		if (error_msgs(llama))
			return (1);
	}
	if (llama->mode == 1)
		ft_printf("Missing start [%d] and/or end [%d]\n", start, end);
	return (0);
}
