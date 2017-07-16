/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_room_links.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:25:00 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:50:06 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	display_room_links(t_lame *llama)
{
	t_room	*tmp;
	int		x;

	tmp = llama->rooms;
	while (tmp)
	{
		if (tmp->door_count > 0)
		{
			x = -1;
			if (tmp->start == 1)
				ft_printf("Room [.blue.%s.] (start) has %d doors:\n",
						tmp->name, tmp->door_count);
			else if (tmp->end == 1)
				ft_printf("Room [.red.%s.] (end) has %d doors:\n",
						tmp->name, tmp->door_count);
			else
				ft_printf("%s has %d doors\n", tmp->name, tmp->door_count);
			while (tmp->door_names[++x])
			{
				ft_printf("[.green.->.] %s\n", tmp->door_names[x]);
			}
		}
		tmp = tmp->next;
	}
}
