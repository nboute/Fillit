/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:05:08 by niboute           #+#    #+#             */
/*   Updated: 2019/08/01 16:41:04 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_place_piece(int *pxy, t_tetri *piece, char **tab, char size)
{
	int		x;
	int		y;
	int		placed;

	y = 0;
	placed = 0;
	while (y < 4 && y + pxy[1] < size)
	{
		x = 0;
		while (x < 4 && x + pxy[0] < size)
		{
			if (piece->content[y][x] != '.')
			{
				if (tab[pxy[1] + y][pxy[0] + x] != '.')
					return (0);
				tab[pxy[1] + y][pxy[0] + x] = piece->letter;
				placed++;
			}
			x++;
		}
		y++;
	}
	return (placed == 4 ? 1 : 0);
}

int			ft_place_tetri(short pos, t_tetri *piece, char **tab, char size)
{
	int	pxy[2];

	pxy[0] = pos % size;
	pxy[1] = pos / size;
	return (ft_place_piece((int*)pxy, piece, tab, size));
}

void		ft_remove_piece(char letter, char **tab, char size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == letter)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int			ft_fillit_backtrack(t_tetri *piece, char **tab, char size,
			short pos)
{
	int		i;

	pos = 0;
	if (!piece)
		return (1);
	while (pos < size * size)
	{
		i = 0;
		if (ft_place_tetri(pos, piece, tab, size))
		{
			if (ft_fillit_backtrack(piece->next, tab, size, 0))
				return (1);
		}
		ft_remove_piece(piece->letter, tab, size);
		pos++;
	}
	return (0);
}

void		ft_solve(t_tetri *list, int number)
{
	int		size;
	int		solved;
	char	**tab;
	int		i;

	tab = NULL;
	size = 2;
	while (size * size < number)
		size++;
	solved = 0;
	while (!solved)
	{
		if (tab)
			ft_tabdel((void***)&tab, size - 1);
		tab = ft_create_tab(size);
		solved = ft_fillit_backtrack(list, tab, size, 0);
		size++;
	}
	i = 0;
	while (i < size - 1)
		ft_putendl(tab[i++]);
	if (tab)
		ft_tabdel((void***)&tab, size - 1);
}
