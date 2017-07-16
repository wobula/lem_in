/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_doors_to_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:02:57 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 08:07:01 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_door_count(t_room *rooms, t_lemk *links)
{
	t_room	*tmp;
	t_lemk	*tmp2;

	tmp = rooms;
	while (tmp)
	{
		tmp2 = links;
		while (tmp2)
		{
			if (ft_strcmp(tmp->name, tmp2->r1) == 0)
				tmp->door_count++;
			if (ft_strcmp(tmp->name, tmp2->r2) == 0)
				tmp->door_count++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int		compare(t_room *tmp, t_lemk *tmp2, int x)
{
	if (ft_strcmp(tmp->name, tmp2->r1) == 0)
	{
		tmp->door_names[x] = ft_strdup(tmp2->r2);
		x++;
	}
	if (ft_strcmp(tmp->name, tmp2->r2) == 0)
	{
		tmp->door_names[x] = ft_strdup(tmp2->r1);
		x++;
	}
	return (x);
}

void	get_doors(t_room *rooms, t_lemk *links)
{
	t_room	*tmp;
	t_lemk	*tmp2;
	int		x;

	tmp = rooms;
	tmp2 = links;
	while (tmp)
	{
		if (tmp->door_count > 0)
		{
			tmp->door_names = (char **)ft_memalloc(sizeof(char*)
				* (tmp->door_count + 1));
			tmp->door_names[tmp->door_count] = 0;
		}
		tmp2 = links;
		x = 0;
		while (tmp2)
		{
			x = compare(tmp, tmp2, x);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	add_doors_to_rooms(t_lame *llama)
{
	get_door_count(llama->rooms, llama->links);
	get_doors(llama->rooms, llama->links);
}
