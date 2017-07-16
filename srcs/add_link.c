/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:17:47 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 08:11:05 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemk	*new(t_lame *llama, t_lemk *tmp)
{
	if (!llama->links)
	{
		llama->links = (t_lemk *)ft_memalloc(sizeof(t_lemk));
		tmp = llama->links;
	}
	else
	{
		tmp = llama->links;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_lemk *)ft_memalloc(sizeof(t_lemk));
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_link(t_lame *llama, char *line)
{
	t_lemk	*tmp;
	int		x;
	int		y;

	tmp = NULL;
	tmp = new(llama, tmp);
	x = -1;
	while (line[++x] != '-')
		;
	tmp->r1 = ft_strsub(line, 0, x);
	y = x + 1;
	while (line[++x])
		;
	tmp->r2 = ft_strsub(line, y, x);
	tmp->next = NULL;
}

int		check_for_links(char *line)
{
	int x;

	x = -1;
	if (!ft_isprint(line[0]) || line[0] == '#' || line[0] == '-')
		return (0);
	while (line[++x] && line[x] != '-')
		;
	if (line[x] != '-')
		return (0);
	while (line[++x] && line[x] != '-')
		;
	if (line[x] == '\0')
		return (1);
	return (0);
}

int		get_links(t_lame *llama, char *line)
{
	if (!check_for_links(line))
		return (0);
	add_link(llama, line);
	llama->link_count++;
	return (1);
}
