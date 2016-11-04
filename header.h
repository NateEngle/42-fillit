/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 23:03:10 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/28 11:42:39 by nengle-          ###   ########.fr       */
/*   Updated: 2016/10/28 11:40:03 by jcapling         ###   ########.fr       */
/*   Updated: 2016/10/30 19:06:21 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H_
# define HEADER_H_

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

//int		valid_nums(char *map);
char	**make_letters(char **tet);
char	*ft_change_pound(char *tet, char alpha);
char	*read_file(char *file);
int		check_valid(char **str);
//int		find_like(char **shapes, int holder);
//int		confirm_pound(char *tet, int j);
//int		pound_num(char **shapes, int x, int y, int pound);
int		type_block(char *tet, char **shapes);
char	**split_input(char *map);

#endif
