/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:36:46 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/27 14:11:22 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	valid_nums(char *map)
{
	int i;
	int pound;
	int empty;

	i = 0;
	pound = 0;
	empty = 0;
	while (map[i])
	{
		if (map[i] == '#')
			pound++;
		else if (map[i] == '.')
			empty++;
		else if (map[i] != '\n')
			return (0);
		i++;
	}
	if (pound != 4)
		return (0);
	if (empty != 12)
		return (0);
	return (1);
}

// int check_shape(char *map)
// {
// 	int	index;

// 	index = 0;
// 	if 
// 	if (map[index] == '#' && map[index + 1] == '#')
// 	{
// 		if (map[index + 5] == '#'
// 	}
// }

// int	check_valid(char **tetriminos)
// {
//     int i;

//     i = 0;
//     while (tetriminos[i] != '\0')
//     {   
//         if(!(valid_nums(tetriminos[i])))
//             return (0);
//         if (!(check_shape(tetriminos[i]);
//             return (0);
//         i++;
//     }
//     return (1);
// }

// char **set_map(char **av)
// {
//     char **map;

//     if (!(map = (char **)malloc(sizeof(char *) *                

// }
