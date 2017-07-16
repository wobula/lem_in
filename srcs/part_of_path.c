/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:45:25 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:45:31 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		end_room(t_lame *llama, t_room *tmp, int y)
{
	if (llama->mode == 1)
		ft_printf("Found end room at %s\n", tmp->name);
	tmp->path = 1;
	tmp->pos = y + 1;
	return (1);
}

int		part_of_path(t_room *tmp, int y)
{
	tmp->path = 1;
	tmp->pos = y + 1;
	return (1);
}
