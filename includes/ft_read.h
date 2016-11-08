/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:22:16 by nboute            #+#    #+#             */
/*   Updated: 2016/11/08 18:05:13 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H

# define FT_READ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.a"

typedef	struct		s_tetris
{
	char			data[21];
	char			letter;
	int				placed;
	struct s_tetris	*next;
}					t_tetris;

#endif
