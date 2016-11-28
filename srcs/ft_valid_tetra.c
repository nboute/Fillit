/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:08:53 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/28 20:24:53 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_check_case(char **cs, char c)
{
	int	y;
	int x;
	int error;
	int ht;

	y = 0;
	error = 0;
	ht = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (cs[y][x] == c)
				ht++;
			else if (cs[y][x] != c && cs[y][x] != '.')
				error++;
			x++;
		}
		y++;
	}
	return ((error == 0 && ht == 4) ? 1 : 0);
}

int	count(char **tetra, int x, int y, char c)
{
	int s;

	s = 0;
	if (x != 3 && tetra[y][x] == c && tetra[y][x + 1] == c)
		s++;
	if (x != 0 && tetra[y][x] == c && tetra[y][x - 1] == c)
		s++;
	if (y != 3 && tetra[y][x] == c && tetra[y + 1][x] == c)
		s++;
	if (y != 0 && tetra[y][x] == c && tetra[y - 1][x] == c)
		s++;
	return (s);
}

int	ft_tetra(char **tetra, char c)
{
	int x;
	int y;
	int s;

	y = 0;
	s = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			if (tetra[y][x] == c)
				s += count(tetra, x, y, c);
			x++;
		}
		y++;
	}
	return (s == 6 || s == 8 ? 1 : 0);
}

int	ft_valid_tetra(char **tetra, char c)
{
	int a;
	int i;

	a = 0;
	i = 0;
	a = ft_check_case(tetra, c);
	if (a == 1)
		a += ft_tetra(tetra, c);
	return (a == 2 ? 1 : 0);
}
