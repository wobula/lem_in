/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:48:54 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:51:05 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_lemks(t_lemk *links)
{
	t_lemk *cur;
	t_lemk *prv;

	prv = links;
	cur = links;
	while (cur)
	{
		cur = cur->next;
		ft_strdel(&prv->r1);
		ft_strdel(&prv->r2);
		ft_memdel((void*)&prv);
		prv = cur;
	}
	ft_memdel((void*)&prv);
}

void	del_rooms(t_room *rooms)
{
	int x;

	x = -1;
	if (!rooms->door_names)
		return ;
	while (rooms->door_names[++x])
		ft_strdel(&rooms->door_names[x]);
	ft_memdel((void*)&rooms->door_names);
}

void	free_rooms(t_lame *llama)
{
	t_room *tmp;

	tmp = llama->rooms->next;
	while (tmp)
	{
		if (llama->rooms->door_names)
			del_rooms(llama->rooms);
		if (llama->rooms->name)
			ft_strdel(&llama->rooms->name);
		ft_memdel((void*)&llama->rooms);
		llama->rooms = tmp;
		tmp = tmp->next;
	}
	if (llama->rooms->name)
		ft_strdel(&llama->rooms->name);
	del_rooms(llama->rooms);
	ft_memdel((void*)&llama->rooms);
}

void	free_all(t_lame *llama)
{
	if (llama->rooms)
		free_rooms(llama);
	if (llama->links)
		delete_lemks(llama->links);
	ft_strdel(&llama->raw);
	ft_memdel((void*)&llama);
}
