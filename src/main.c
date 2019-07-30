/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:58:59 by niboute           #+#    #+#             */
/*   Updated: 2019/07/30 15:00:07 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include <unistd.h>
#include <fcntl.h>

int			main(int ac, char **av)
{
	int		fd;
	t_tetri	*list;

	if (ac != 2)
	{
		ft_putendl_fd("usage: ./fillit [file]", 2);
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(list = try_parse(fd)))
	{
		ft_putendl("error");
		return (0);
	}
	indent_list(list);
	ft_solve(list, list_size(list));
}
