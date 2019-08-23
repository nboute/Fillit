/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:14:13 by niboute           #+#    #+#             */
/*   Updated: 2019/08/01 17:42:04 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int			check_tetri(char *str)
{
	int		i;
	int		side_count;

	i = 0;
	side_count = 0;
	while (str[i])
	{
		if (i > 4)
			if (str[i] == '#' && str[i - 5] == '#')
				side_count++;
		if (i < 14)
			if (str[i] == '#' && str[i + 5] == '#')
				side_count++;
		if (i % 5 > 0)
			if (str[i] == '#' && str[i - 1] == '#')
				side_count++;
		if (i % 5 < 4)
			if (str[i] == '#' && str[i + 1] == '#')
				side_count++;
		i++;
	}
	if (side_count == 6 || side_count == 8)
		return (1);
	return (0);
}

int			add_tetri_to_lst(t_tetri *new, t_tetri **list)
{
	char	letter;
	t_tetri	*ptr;

	if (!*list)
	{
		*list = new;
		new->letter = 'A';
		return (1);
	}
	letter = 'B';
	ptr = *list;
	while (ptr->next)
	{
		letter++;
		ptr = ptr->next;
	}
	ptr->next = new;
	new->letter = letter;
	return (letter > 'Z' ? 0 : 1);
}

int			add_tetri(char *str, t_tetri **list)
{
	t_tetri	*new;
	int		i;
	int		j;

	if (!check_tetri(str))
		return (0);
	if (!(new = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			new->content[i][j] = *(str++);
		str++;
	}
	new->next = NULL;
	return (add_tetri_to_lst(new, list));
}

int			check_str(char *str, t_tetri **list)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (j == 4 || i == 20)
		{
			if (str[i] != '\n')
				return (0);
			j = -1;
		}
		else if (str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '#')
			count++;
		i++;
		j++;
	}
	if (count != 4)
		return (0);
	return (add_tetri(str, list));
}

t_tetri		*try_parse(int fd)
{
	char	buff[21];
	int		ret;
	int		old_ret;
	t_tetri	*lst;

	lst = NULL;
	old_ret = -1;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (ret < 19 || !check_str(buff, &lst))
		{
			destroy_list(&lst);
			return (NULL);
		}
		old_ret = ret;
	}
	if (old_ret == 21 && ret == 0)
		destroy_list(&lst);
	return (lst);
}
