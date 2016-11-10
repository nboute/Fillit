/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:17:10 by nboute            #+#    #+#             */
/*   Updated: 2016/11/10 13:50:13 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/ft_read.h"

int		main(int ac, char **av)
{
	t_tetris	*list;
	char		**grid;
	t_in

	grid = NULL;
	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if ((list = ft_read(av[1])) == NULL)
		return (0);
	while (!grid)
	{
		if ((grid = ft_alloc_grid()) == NULL)
		return (0);
	}
}
