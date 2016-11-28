/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:21:09 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 17:44:34 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_format(char *str)
{
	int	i;
	int	t;
	int	l;
	int	j;

	i = 0;
	t = 0;
	while (str[i])
	{
		l = 0;
		j = 0;
		while (j <= 4 && str[i])
		{
			if (str[i] == '\n')
				if (j++ < 4 && l != 4)
					return (0);
			if ((str[i] != '\n') && ((j == 4 && str[i + 1] != '\n') ||
					(str[i] != '.' && str[i] != '#') || l >= 5))
				return (0);
			l = (str[i++] == '\n') ? 0 : l + 1;
		}
		if ((j == 4 && str[i]) || j < 4 || (j == 5 && !str[i]) || !(++t))
			return (0);
	}
	return ((t == 0 || t > 25) ? 0 : t);
}

t_info	*ft_check(char *str, t_info **blocks)
{
	int		i;
	int		t;
	int		n;

	i = 0;
	if (!(n = ft_check_format(str)))
		return (NULL);
	t = 0;
	(*blocks)->nb_blocks = n;
	while (t < n)
	{
		if (!ft_add_tetrimino(blocks,
				ft_strsub((char const*)str, t++ * 21, 21)))
			return (NULL);
	}
	return (*blocks);
}

char	*ft_strreplace(char *str, char c, char new)
{
	short	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = new;
		i++;
	}
	return (str);
}

t_info	**ft_add_tetrimino(t_info **blocks, char *content)
{
	t_tetris		*tmp;
	t_tetris		*elem;

	if ((elem = (t_tetris*)malloc(sizeof(struct s_tetris))) == NULL)
		return (NULL);
	elem->next = NULL;
	elem->placed = 0;
	if (!((*blocks)->list))
	{
		elem->letter = 'A';
		(*blocks)->list = elem;
	}
	else
	{
		tmp = (*blocks)->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->letter = tmp->letter + 1;
	}
	elem->data = ft_strsplit(ft_strreplace(content, '#', elem->letter), '\n');
	free(content);
	if (!ft_valid_tetra(elem->data, elem->letter))
		return (NULL);
	return (blocks);
}

t_info	*ft_read(char *fn)
{
	t_info		*blocks;
	int			ret;
	char		buff[BUFF_SIZE];
	int			fd;

	if ((fd = open(fn, O_RDONLY)) == -1)
		return (NULL);
	if ((blocks = (t_info*)malloc(sizeof(struct s_info))) == NULL)
		return (NULL);
	blocks->list = NULL;
	if ((ret = read(fd, buff, BUFF_SIZE)) <= 0)
		return (NULL);
	if (*buff != '.' && *buff != '#')
		return (NULL);
	buff[ret] = '\0';
	if (!ft_check(buff, &blocks))
		return (NULL);
	return (blocks);
}
