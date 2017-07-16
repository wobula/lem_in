/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:16:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 07:16:10 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	first_room(t_lame *llama, char *line, int x)
{
	llama->rooms = (t_room *)ft_memalloc(sizeof(t_room));
	llama->rooms->next = NULL;
	llama->rooms->name = ft_strsub(line, 0, x);
	llama->rooms->start = 0;
	llama->rooms->end = 0;
	llama->rooms->checked = 0;
	llama->rooms->path = 0;
	llama->rooms->pos = -1;
	llama->rooms->ant_count = 0;
	if (llama->start_on == 1)
	{
		llama->rooms->start = 1;
		llama->start_on = 0;
	}
	if (llama->end_on == 1)
	{
		llama->rooms->end = 1;
		llama->end_on = 0;
	}
}

void	additional_rooms(t_lame *llama, char *line, int x)
{
	t_room *tmp;

	tmp = llama->rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_room *)ft_memalloc(sizeof(t_room));
	tmp->next->name = ft_strsub(line, 0, x);
	tmp->next->next = NULL;
	tmp->next->start = 0;
	tmp->next->end = 0;
	tmp->next->checked = 0;
	tmp->next->path = 0;
	tmp->next->pos = -1;
	tmp->next->ant_count = 0;
	if (llama->start_on == 1)
	{
		tmp->next->start = 1;
		llama->start_on = 0;
	}
	if (llama->end_on == 1)
	{
		tmp->next->end = 1;
		llama->end_on = 0;
	}
}

void	add_room(t_lame *llama, char *line)
{
	int		x;

	x = -1;
	while (line[++x] != ' ')
		;
	if (!llama->rooms)
		first_room(llama, line, x);
	else
		additional_rooms(llama, line, x);
}
