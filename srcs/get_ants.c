/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:55:02 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:55:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_ants(char *str)
{
	int x;

	x = -1;
	while (str[++x])
	{
		if (!ft_isdigit(str[x]))
			return (0);
	}
	return (1);
}

int		get_ants(t_lame *llama, char *line)
{
	if (!check_ants(line))
		return (0);
	llama->ant_count = ft_atoi(line);
	return (1);
}
