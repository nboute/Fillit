/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:22:16 by nboute            #+#    #+#             */
/*   Updated: 2016/11/10 14:24:24 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H

# define FT_READ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct		s_tetris
{
	char			**data;
	char			letter;
	int				placed;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_info
{
	int				nb_blocks;
	struct s_tetris	*list;
}					t_info;

#endif
