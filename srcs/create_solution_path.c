/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_solution_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:04:51 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:48:29 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*get_head(t_room *rooms)
{
	t_room *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->start == 1)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

t_room	*get_next(t_room *rooms, int pos)
{
	t_room *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->pos == pos)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	create_solution_path(t_lame *llama, t_room *rooms)
{
	t_room	*tmp;
	t_room	*next;
	int		pos;

	pos = 1;
	llama->solution = get_head(rooms);
	next = get_next(rooms, pos);
	tmp = llama->solution;
	tmp->prev = NULL;
	while (next->end == 0)
	{
		next->prev = tmp;
		tmp->solution = next;
		tmp = tmp->solution;
		pos++;
		next = get_next(rooms, pos);
	}
	next->prev = tmp;
	tmp->solution = next;
}
