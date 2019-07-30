/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboute <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:05:35 by niboute           #+#    #+#             */
/*   Updated: 2019/07/30 14:58:55 by niboute          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_tetri
{
	char			**content;
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

char				**ft_solve(t_tetri *list, int number);
char				**ft_create_tab(char size);
void				indent_list(t_tetri *list);
int					list_size(t_tetri *list);
t_tetri				*try_parse(int fd);

#endif
