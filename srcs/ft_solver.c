/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:18:17 by nboute            #+#    #+#             */
/*   Updated: 2016/11/09 23:59:49 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_read.h"

int		ft_parse_t(t_tetris *tetrimino, char **grid, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetrimino->data[i] && grid[x][y])
	{
		if (tetrimino->data[i] == '\n')
		{
			y++;
			x -= (i - j) % 4;
			j++;
		}
		else if (tetrimino->data[i] == '#')
		{
			if (grid[y][x] != '.')
				return (0);
			grid[x][y] = tetrimino->data[i];
			x++;
		}
		i++;
	}
	if (!tetrimino->data[i])
		return (0);
	return (1);
}

int		ft_tryparse_t(t_tetris *tetrimino, char **grid, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	if (ft_parse_t(tetrimino, grid, y, x))
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (grid[y + i][x + j] == tetrimino->letter)
					grid[y + i][x + j] = '.';
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

//	Fonction qui effectue le backtracking

char	**ft_solve(char **grid, t_tetris *l, t_tetris *elem)
{
	int			x;
	int			y;
	char		**tmp;

	y = 0;
	if (!l)
		return (grid);
	while(*grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x])
			{
				if (ft_tryparse_t(elem, grid, y, x))
					if (tmp = ft_solve(grid, l, l))
			}
			x++;
		}
		y++;
	}
	return (grid);
}
