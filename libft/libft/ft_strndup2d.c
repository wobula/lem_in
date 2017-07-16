/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:00:31 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/22 13:01:56 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strndup2d(char **str2d, int s, int end)
{
	char	**new;
	int		x;
	int		y;

	x = 0;
	y = s;
	while (str2d[y] != str2d[end])
	{
		if (str2d[y][0] == '>' && str2d[y][0] == '<' && (y = y + 2))
			continue ;
		x++;
		y++;
	}
	new = (char**)ft_memalloc(sizeof(char*) * (x + 1));
	new[x] = 0;
	x = 0;
	while (str2d[s] != str2d[end])
	{
		if (str2d[s][0] == '>' && str2d[s][0] == '<' && (s = s + 2))
			continue ;
		new[s] = ft_strdup(str2d[s]);
		s++;
	}
	return (new);
}
