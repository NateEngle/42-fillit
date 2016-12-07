/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:43:26 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:43:27 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*solver(t_list *list)
{
	t_map *map;
	int size;

	size = approx_sqrt(ft_lstcount(list) * 4);
	map = map_creator(size);
	while (!fillit_solver(list, map))
	{
		delete_map(map);
		size++;
		map = map_creator(size);
	}
	return (map);	
}

int	fillit_solver(t_list *list, t_map *map)
{
	int i;
	int j;
	t_piece	*piece;

	if (list == NULL)
		return (1);
	piece = (t_piece *)(list->content);
	i = 0;
	while (i < map->size - piece->height + 1)
	{
		j = 0;
		while (j < map->size - piece->width + 1)
		{
			if (put_piece(piece, map, i, j))
			{
				if (fillit_solver(list->next, map))
					return (1);
				else
					piece_converter(piece, map, new_coord(i, j), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

int approx_sqrt(int n)
{
	int i;

	i = 2;
	if (n == 1 || n == 0)
		return (n);
	while (i * i < n)
		i++;
	return (i);
}