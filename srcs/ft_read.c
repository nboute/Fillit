/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:21:09 by nboute            #+#    #+#             */
/*   Updated: 2016/11/08 17:17:47 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_read.h"

t_tetris	**ft_add_tetrimino(t_tetris **start, char *content)
{
	t_tetris	*tmp;
	t_tetris	*elem;

	if ((!content || elem = (t_tetris*)malloc(sizeof(s_tetris))) == NULL)
		return (NULL)
	ft_strcpy(elem->data, content);
	if (!*start)
	{
		elem->letter = 'A';
		return (elem);
	}
	else
	{
		tmp = start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->letter = tmp->letter + 1;
	}
	return (start);
}

t_tetris	*ft_read(char *fn)
{
	t_tetris	*start;
	int			ret;
	char		buff[21];
	int			fd;

	start = NULL;
	if ((fd = open(fn, O_RDONLY)) == -1)
		return (NULL);
	while (ret = read(fd, buff, 21))
	{
		buff[ret] = '\0';
		ft_add_tetrimino(&start, buff);
	}
	return (start);
}
