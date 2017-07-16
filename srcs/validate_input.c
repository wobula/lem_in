/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:55:20 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 10:19:54 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	display_error(t_lame *llama)
{
	ft_printf("[.blue.Summary:.]\n");
	if (llama->ant_count == 0)
		ft_printf("No ants :(\n");
	else
		ft_printf("There were %d ants\n", llama->ant_count);
	if (llama->room_count == 0)
		ft_printf("No rooms :(\n");
	else
		ft_printf("There were %d rooms\n", llama->room_count);
	if (llama->link_count == 0)
		ft_printf("No doors :(\n");
	else
		ft_printf("There were %d doors\n", llama->link_count);
}

int		display_input(t_lame *llama)
{
	int ret;

	ret = 1;
	if (llama->ant_count == 0)
		ret = 0;
	if (llama->room_count == 0)
		ret = 0;
	if (llama->link_count == 0)
		ret = 0;
	if (llama->mode == 1)
		display_error(llama);
	return (ret);
}

t_room	*get_origin(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->start == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		multiple_start_exit(t_lame *llama)
{
	int		start;
	int		end;
	t_room	*tmp;

	tmp = llama->rooms;
	start = 0;
	end = 0;
	while (tmp)
	{
		if (tmp->start == 1)
			start++;
		if (tmp->end == 1)
			end++;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
		return (1);
	if (llama->mode == 1)
		ft_printf("[.red.Bad start %d and/or exit %d count.]\n", start, end);
	return (0);
}

int		validate_input(t_lame *llama)
{
	int ret;

	ret = 1;
	if (!display_input(llama))
		ret = 0;
	if (!display_rooms(llama))
		ret = 0;
	if (!multiple_start_exit(llama))
		ret = 0;
	if (ret == 0)
		return (0);
	if (!validate_path(llama, llama->rooms))
	{
		ret = 0;
		if (llama->mode == 1)
			ft_printf("[.red.No valid path Found.]\n");
	}
	else if (llama->mode == 1)
		ft_printf("[.green.Valid.] path exists!\n");
	return (ret);
}
