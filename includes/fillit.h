/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 23:03:10 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/11 20:53:53 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		valid_nums(char *map);
char	***make_letters(char ***tet);
char	*ft_change_pound(char *tet, char alpha);
char	*read_file(char *file);
int		check_valid(char **str);
int		find_like(char **shapes, int holder);
int		confirm_pound(char *tet, int j);
int		pound_num(char **shapes, int x, int y, int pound);
int		type_block(char *tet, char **shapes);
char	**split_input(char *buf, int count);
int		max_num(int size);
char	**make_map(int max_num);
char	**grab_tetri(char **str);
char	*printables(int enums);
char	**get_dblchar(char *split);
int		**coordinates(int enums);
int		block_num(char *holder);
char	***group_tets(char **tet, int count);
int		place_tet(char **piece, char **map, int x, int y);
void	convert_tet(char **piece, char **map, int x, int y);
char	**solver(char ***group, int count);
int		fillit_solve(char ***total, int k, char **map, int size);
int		tet_width(char **tet);
int		get_height(int k);
int		get_width(int k);
int		tet_height(char **tet);
char	*get_places(int k);
void	convert_to_dot(char **piece, char **map, int x, int y);
void	delete_map(char **map);
void	print_map(char **map);
int		cnt_check(char *str);

#endif
