/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:00:50 by rschramm          #+#    #+#             */
/*   Updated: 2017/05/30 09:58:36 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*get_end(t_room *start)
{
	t_room *tmp;

	tmp = start;
	while (tmp->solution)
		tmp = tmp->solution;
	return (tmp);
}

void	print_output(int count, char *name)
{
	ft_putchar('L');
	ft_putnbr(count);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

int		move_the_ants(t_room *start)
{
	t_room	*tmp;
	int		count;
	int		end_ant_count;

	tmp = get_end(start);
	end_ant_count = tmp->ant_count;
	count = tmp->ant_count;
	while (tmp->prev)
	{
		if (tmp->prev->ant_count > 0)
		{
			tmp->ant_count++;
			tmp->prev->ant_count--;
			count++;
			print_output(count, tmp->name);
		}
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	return (end_ant_count);
}

void	solve(t_lame *llama)
{
	llama->solution->ant_count = llama->ant_count;
	while ((move_the_ants(llama->solution)) != llama->ant_count)
		;
}
