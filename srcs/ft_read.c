/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:21:09 by nboute            #+#    #+#             */
/*   Updated: 2016/11/14 09:55:44 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_read.h"

char	**ft_check_format(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	if ((tab = ft_strsplit(str, '\n')) == NULL)
		return (NULL);
	while (*tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j > 3)
			return (NULL);
		i++;
	}
	if (i > 3)
		return (NULL);
	return (tab);
}

t_info	**ft_add_tetrimino(t_info **blocks, char *content)
{
	t_tetris	*tmp;
	t_tetris		*elem;

	if ((elem = (t_tetris*)malloc(sizeof(struct s_tetris))) == NULL)
		return (NULL);
	if (!content)
		return (NULL);
	if ((elem->data = ft_check_format(content)) == NULL)
		return (NULL);
	if (!((*blocks)->list))
	{
		elem->letter = 'A';
		(*blocks)->list = elem;
		return (blocks);
	}
	else
	{
		tmp = (*blocks)->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->letter = tmp->letter + 1;
	}
	elem->placed = 0;
	return (blocks);
}

t_info	*ft_read(char *fn)
{
	t_info		*blocks;
	int			ret;
	char		buff[21];
	int			fd;

	if ((fd = open(fn, O_RDONLY)) == -1)
		return (NULL);
	if ((blocks = (t_info*)malloc(sizeof(struct s_info))) == NULL)
		return (NULL);
	blocks->list = NULL;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		ft_add_tetrimino(&blocks, buff);
	}
	return (blocks);
}
