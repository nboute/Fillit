/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:49:18 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 12:25:06 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*ft_gett(int p, int s)
{
	int	*t;

	if (!(t = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	t[0] = p / s;
	t[1] = p % s;
	return (t);
}

int		*ft_getp(char **data)
{
	int	*p;

	if (!(p = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	p[0] = 0;
	while (p[0] < 4)
	{
		p[1] = 0;
		while (p[1] < 4)
		{
			if (data[p[0]][p[1]] != '.')
				return (p);
			p[1]++;
		}
		p[0]++;
	}
	return (p);
}

int		ft_insert_t(char **data, char **grid, int *t, int s)
{
	int	i;
	int	j;
	int	*p;

	p = ft_getp(data);
	i = -1;
	while (++i < 4 && ((j = -1)))
	{
		while (++j < 4)
		{
			if (data[i][j] != '.')
			{
				if ((t[0] + i - p[0]) < 0 || (t[1] + j - p[1]) < 0
				|| t[0] + (i - p[0]) >= s || t[1] + (j - p[1]) >= s)
					return (0);
				if (grid[t[0] + (i - (p[0]))][t[1] + (j - (p[1]))] != '.')
					return (0);
				grid[t[0] + (i - (p[0]))][t[1] + (j - (p[1]))] = data[i][j];
			}
		}
	}
	free(p);
	return (1);
}

void	ft_delete(char **grid, char c)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == c)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_tryinsert_t(t_tetris *tetrimino, char **grid, int *t, int size)
{
	int	i;

	i = 0;
	if (!ft_insert_t(tetrimino->data, grid, t, size))
	{
		ft_delete(grid, tetrimino->letter);
		return (0);
	}
	else
		tetrimino->placed = 1;
	return (1);
}
