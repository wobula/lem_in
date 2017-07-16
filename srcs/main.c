/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:46:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/07/16 14:43:41 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lame	*init_struct(int argc)
{
	t_lame *new;

	new = (t_lame *)ft_memalloc(sizeof(t_lame));
	new->ant_count = 0;
	new->room_count = 0;
	new->link_count = 0;
	new->rooms = NULL;
	new->links = NULL;
	new->start_on = 0;
	new->end_on = 0;
	new->x = -1;
	new->tmp = NULL;
	if (argc == 2)
		new->mode = 1;
	else
		new->mode = 0;
	new->raw = NULL;
	return (new);
}

int		arg_parse(int argc, char **argv)
{
	int ret;

	ret = 1;
	if (argc != 2 && argc != 3)
		ret = 0;
	if (argc == 3)
	{
		if ((ft_strcmp(argv[1], "-v")) != 0)
			ret = 0;
	}
	if (ret == 0)
		ft_putstr("lem-in: error\nlem-in: usage: lem_in [-v] < [file]\n");
	return (ret);
}

int		main(int argc, char **argv)
{
	t_lame *llama;

	if (!arg_parse(argc, argv))
		return (0);
	llama = init_struct(argc);
	if (!get_input(llama))
	{
		ft_putstr("Error\n");
		if (llama->mode == 1)
			ft_printf("[.red.Invalid.] input\n");
		free_all(llama);
		return (0);
	}
	if (llama->mode == 1 && (ft_printf("[.green.Valid.] input\n")))
		display_room_links(llama);
	create_solution_path(llama, llama->rooms);
	ft_printf("%s\n", llama->raw);
	solve(llama);
	free_all(llama);
	return (0);
}
