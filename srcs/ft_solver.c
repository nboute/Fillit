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

char	**ft_solve(char **grid, t_tetris *l, int size)
{
	int			pos;
	char		**tmp;
	t_tetris	*elem;

	if (!l)
		return (grid);
	elem = l;
	while (elem)
	{
		pos = 0;
		while (pos / size < size)
		{
			if (grid[pos / size][pos % size] && !elem->placed)
			{
				if (ft_tryparse_t(elem, grid, pos / size, pos % size))
					if ((tmp = ft_solve(grid, l, size)) != NULL)
						return (tmp);
			}
			pos++;
		}
	elem = elem->next;
	}

	return (NULL);
}

char	**ft_tabnew(int y, int x, char c)
{
	int	i;
	int	j;
	char	**tab;

	if ((tab = (char**)malloc(sizeof(char*) * (y + 1))) == NULL)
		return (NULL);	
	i = 0;
	while (i < y)
	{
		if ((tab[i] = (char*)malloc(x + 1)) == NULL)
			return (NULL);
		j = 0;
		while (j < x)
			tab[i][j++] = c;
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

//la variable size correspond a la premiere racine entiere du carre egal ou superieur au nombre de blocs

char	**ft_solver(t_info *blocks, int size)
{
	char	**grid;
	char 	**tmp;

	grid = NULL;	
	while (!grid)
	{
		tmp = ft_tabnew(size, size, '.');
		grid = ft_solve(tmp, blocks->list, size);
//Une des fonctions de ma libft, que je rajouterai. Elle free juste un tableau a double entree.
		ft_tabdel(tmp);
		size++;
	}
	ft_affgrid(grid);
	free(grid);
}
