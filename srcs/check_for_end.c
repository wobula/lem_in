/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:08:09 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:44:33 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		error_msg(t_lame *llama, t_room *tmp, char *err)
{
	if (llama->mode == 1)
		ft_printf("%s %s\n", err, tmp->name);
	return (0);
}

void	recurse_info(t_lame *llama, t_room *tmp, int test)
{
	if (llama->mode == 1 && test == 1)
		ft_printf("room %s isn't the end; checking doors\n", tmp->name);
	else if (llama->mode == 1 && test == 2)
		ft_printf("checking door %s in room %s\n",
			tmp->door_names[llama->x], tmp->name);
}

int		bad_room(t_lame *llama, t_room *tmp)
{
	if (tmp->checked == 1)
		return ((error_msg(llama, tmp, "Already checked room")));
	tmp->checked = 1;
	if (tmp->door_count == 0)
		return ((error_msg(llama, tmp, "Dead end at")));
	else if (tmp->start == 1)
		return ((error_msg(llama, tmp, "Back in start room at")));
	return (1);
}

int		recursage(t_lame *llama, t_room *tmp, int y)
{
	recurse_info(llama, tmp, 1);
	llama->x = -1;
	while (tmp->door_names[++llama->x])
	{
		recurse_info(llama, tmp, 2);
		if ((check_for_end(llama, tmp->door_names[llama->x], y + 1)) == 1)
			return (part_of_path(tmp, y));
	}
	return (0);
}

int		check_for_end(t_lame *llama, char *door_name, int y)
{
	t_room	*tmp;

	tmp = llama->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, door_name) == 0)
		{
			if (!bad_room(llama, tmp))
				return (0);
			else if (tmp->end == 1)
				return (end_room(llama, tmp, y));
			else
			{
				if (recursage(llama, tmp, y))
					return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
