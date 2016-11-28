/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:23:08 by nboute            #+#    #+#             */
/*   Updated: 2016/11/28 17:40:51 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# define BUFF_SIZE 1000

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

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

t_info				**ft_add_tetrimino(t_info **blocks, char *content);
t_info				*ft_check(char *str, t_info **blocks);
int					ft_check_format(char *str);
t_info				*ft_read(char *fn);
int					ft_insert_t(char **data, char **grid, int *t, int s);
int					ft_allplaced(t_tetris *list);
char				**ft_solve(char **grid, t_tetris *l,
		t_tetris *elem, int size);
void				ft_solver(t_info *blocks);
void				*ft_error(int err);
int					check_case(char **cs);
int					ft_tetra(char **tetra);
void				ft_aff_grid(char **tab);
void				ft_delete(char **grid, char c);
int					*ft_gett(int p, int s);
int					*ft_getp(char **data);
int					ft_tryinsert_t(t_tetris *tetrimino, char **grid,
		int *t, int size);
int					ft_valid_tetra(char **tetra, char c);
#endif
