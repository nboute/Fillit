/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:17:10 by nboute            #+#    #+#             */
/*   Updated: 2016/11/08 20:55:31 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"includes/ft_read.h"

int		ft_getlen(char *str)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
		if (str[i++] == '#')
			n++;
	return (len);
}

char	**ft_alloc_grid(t_tetris *list)
{
	char			**grid;
	unsigned int	size;
	t_tetris		*tmp;
	int				i;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size += ft_getlen(tmp->data);
		tmp = tmp->next;
	}
	size= size / 2 + size % 2;
	if ((grid = (char**)malloc(sizeof(*grid) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (grid[i] = (char*)malloc(size
	}
}

int		main(int ac, char **av)
{
	t_tetris	*list;
	char		**grid;

	if (ac != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	if ((list = ft_read(av[1])) == NULL)
		return (0);
	if ((grid = ft_alloc_grid(list)) == NULL)
		return (0);;
}
