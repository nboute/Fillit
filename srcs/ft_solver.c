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

int	ft_parse_t(t_tetris *tetrimino, char **grid, int y, int x)
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

int	ft_tryparse_t(t_tetris *tetrimino, char **grid, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	if (ft_parse_t(tetrimino, grid, y, x))
	{
		ft_delete_tetrimino(grid, tetrimino, y, x);
		return (1);
	}
	else
		tetrimino->placed = 1;
	return (0);
}

//	supprime le tetrimino indique de la grille
void	ft_delete_tetrimino(char **grid, t_tetris *tetrimino, int y, int x)
{
	int	i;
	int	j;

	i = 0;
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
}

//	Vérifie si tous les tetriminos sont deja places
int	ft_allplaced(t_tetris *list)
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


//	Fonction qui effectue le backtracking
char	**ft_solve(char **grid, t_tetris *l, t_tetris *elem, int size)
{
	int			pos;
	char		**tmp;

	if (ft_allplaced(l))
		return (grid);
	while (elem)
	{
		pos = 0;
		while (pos / size < size && elem->placed)
		{
			if (grid[pos / size][pos % size] && !elem->placed)
			{
				if (ft_tryparse_t(elem, grid, pos / size, pos % size))
				{
					if ((tmp = ft_solve(grid, l, l, size)) != NULL)
						return (tmp);
					ft_delete_tetrimino(grid, l, pos / size, pos % size);
				}
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
	tmp = NULL;	
	while (!grid)
	{
//Une des fonctions de ma libft, que je rajouterai. Elle free juste un tableau a double entree.
		if (tmp)
			ft_tabdel(tmp);
		tmp = ft_tabnew(size, size, '.');
		grid = ft_solve(tmp, blocks->list, size);
		size++;
	}
	ft_affgrid(grid);
	free(grid);
}
