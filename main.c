/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:58:59 by niboute           #+#    #+#             */
/*   Updated: 2019/08/01 17:37:49 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void		destroy_list(t_tetri **list)
{
	t_tetri	*ptr;
	t_tetri	*tmp;

	ptr = *list;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
	*list = NULL;
}

int			main(int ac, char **av)
{
	int		fd;
	t_tetri	*list;

	list = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit [file]");
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
		close(fd);
		return (0);
	}
	close(fd);
	indent_list(list);
	ft_solve(list, list_size(list));
	destroy_list(&list);
}
