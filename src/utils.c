/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:54:56 by niboute           #+#    #+#             */
/*   Updated: 2019/07/30 15:05:53 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

char		**ft_create_tab(char size)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)malloc(sizeof(char*) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * size)))
			return (0);
		j = 0;
		while (j < size)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

int			list_size(t_tetri *list)
{
	int		nb;

	nb = 0;
	while (list)
	{
		list = list->next;
		nb++;
	}
	return (nb);
}

void		indent_tetri(char **content, int miny, int minx)
{
	int		x;
	int		y;

	y = miny;
	while (y < 4)
	{
		x = minx;
		while (x < 4)
		{
			if (content[y][x] != '.')
			{
				content[y - miny][x - minx] = '#';
				content[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

void		get_indent_tetri(char **content)
{
	int		x;
	int		y;
	int		miny;
	int		minx;

	y = -1;
	miny = 4;
	minx = 4;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (content[y][x] != '.' && y < miny)
				miny = y;
			if (content[y][x] != '.' && x < minx)
				minx = x;
		}
	}
	if (miny || minx)
		indent_tetri(content, miny, minx);
}

void		indent_list(t_tetri *list)
{
	while (list)
	{
		get_indent_tetri(list->content);
		list = list->next;
	}
}
