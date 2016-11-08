/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:18:17 by nboute            #+#    #+#             */
/*   Updated: 2016/11/08 18:52:45 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_read.h"

char	**ft_solve_backtrack(char **grid, t_tetris *tetrimino)
{
	int		x;
	int		y;

	y = 0;
	if (!tetrimino)
		return (1);
	while(*grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x])
			{
				if (try_parse(tetrimino, grid[y][x]))
					ft_solve_backtrack(grid, tetrimino->next)
			}
			x++;
		}
		y++;
	}
}
