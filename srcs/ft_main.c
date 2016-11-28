/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:17:10 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 15:35:32 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_aff_grid(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		ft_putchar('\n');
	}
}

void	*ft_error(int err)
{
	if (err == 0)
		ft_putstr_fd("usage: fillit source_file\n", 2);
	else if (err == 1)
		ft_putstr_fd("error\n", 2);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_info		*blocks;

	if (ac != 2)
		return ((int)ft_error(0));
	if (!(blocks = ft_read(av[1])))
		return ((int)ft_error(1));
	ft_solver(blocks);
}
