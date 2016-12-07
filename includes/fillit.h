/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:44:25 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:44:26 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_map
{
	int			size;
	char		**str;
}				t_map;

typedef struct	s_piece
{
	char		**place;
	int			width;
	int			height;
	char		value;
}				t_piece;

typedef struct 	s_coord
{
	int			x;
	int			y;
}				t_coord;

t_coord		*new_coord(int x, int y);
t_piece		*new_piece(char **place, int width, int height, char value);
void		delete_piece(t_piece  *piece);
t_list		*delete_list(t_list *list);
t_list		*read_funct(int fd);
int			valid_tet(char *buf, int cnt);
int			tet_touch(char	*buf);
char		*reading(char *file);
int			cnt_check(char *str);
t_piece		*get_piece(char *buf, char value);
void		max_coord(char *str, t_coord *min, t_coord *max);
void		delete_map(t_map *map);
void		print_map(t_map *map);
void		piece_converter(t_piece *piece, t_map *map, t_coord *coord, char value);
int			put_piece(t_piece *piece, t_map *map, int x, int y);
t_map		*map_creator(int size);
t_map		*solver(t_list *list);
int			fillit_solver(t_list *list, t_map *map);
int			approx_sqrt(int n);

#endif