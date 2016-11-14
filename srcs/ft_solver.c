/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:18:17 by nboute            #+#    #+#             */
/*   Updated: 2016/11/14 11:06:01 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_read.h"

int		ft_parse_t(t_tetris *tetrimino, char **grid, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tetrimino->data[i] && grid[y][x])
	{
		if (!tetrimino->data[i][j])
		{
			i++;
			y++;
			x -= 3;
			j = 0;
		}
		else if (tetrimino->data[i][j] == '#')
		{
			if (grid[y][x] != '.')
				return (0);
			grid[y][x] = tetrimino->letter;
			x++;
			j++;
		}
	}
	return (1);
}

int		ft_tryparse_t(t_tetris *tetrimino, char **grid, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	if (ft_parse_t(tetrimino, grid, y, x))
	{
		tetrimino->placed = 0;
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
	else
		tetrimino->placed = 1;
	return (0);
}

//	Fonction qui effectue le backtracking

char	**ft_solve(char **grid, t_tetris *l, t_tetris *elem, int size)
{
	int			pos;
	char		**tmp;

	pos = 0;
	if (!l)
		return (grid);
	while (elem)
	{
		pos = 0;
		while (pos / size < size)
		{
			if (grid[pos / size][pos % size] && !elem->placed)
			{
				if (ft_tryparse_t(elem, grid, pos / size, pos % size))
					if ((tmp = ft_solve(grid, l, l, size)) != NULL)
						return (tmp);
			}
			pos++;
		}
	elem = elem->next;
	}

	return (grid);
}

char	**ft_solver(t_info *blocks, int size)
{
	char	**grid;


}
