/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:18:17 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 20:28:59 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_allplaced(t_tetris *list)
{
	t_tetris	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!tmp->placed)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

char	**ft_solve(char **grid, t_tetris *l, t_tetris *elem, int size)
{
	int			pos;
	char		**tmp;
	int			*t;

	if (ft_allplaced(l))
		return (grid);
	pos = 0;
	while (pos / size < size)
	{
		if (grid[pos / size][pos % size])
		{
			t = ft_gett(pos, size);
			if (ft_tryinsert_t(elem, grid, t, size))
			{
				if ((tmp = ft_solve(grid, l, elem->next, size)) != NULL)
					return (tmp);
				ft_delete(grid, elem->letter);
			}
			if (t)
				free(t);
		}
		pos++;
	}
	return (NULL);
}

void	ft_solver(t_info *blocks)
{
	char	**grid;
	char	**tmp;
	int		size;
	int		i;

	grid = NULL;
	tmp = NULL;
	size = blocks->nb_blocks * 4;
	while ((i = ft_sqrt(size)) <= 1 || size < 9)
		size++;
	size = i;
	while (!grid)
	{
		if (tmp)
			ft_tabdel(tmp);
		tmp = ft_tabnew(size, size, '.');
		grid = ft_solve(tmp, blocks->list, blocks->list, size);
		size++;
	}
	ft_aff_grid(grid);
	ft_tabdel(grid);
}
