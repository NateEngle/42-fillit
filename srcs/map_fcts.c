/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:37:16 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:37:18 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_map(t_map *map)
{
	int i;

	i = 0;
	while (map->str[i])
	{
		ft_memdel((void **)(&(map->str[i])));
		i++;
	}
	ft_memdel((void **)&(map->str));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->str[i]);
		ft_putchar('\n');
		i++;
	}
}

void	piece_converter(t_piece *piece, t_map *map, t_coord *coord, char value)
{
	int i;
	int j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->place[i][j] == '#')
				map->str[coord->y + j][coord->x + i] = value;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&coord);
}

int		put_piece(t_piece *piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->place[j][i] == '#' && map->str[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	piece_converter(piece, map, new_coord(x, y), piece->value);
	return (1);
}

t_map	*map_creator(int size)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->str = (char **)ft_memalloc(sizeof(char *) * size);
	while (i < size)
	{
		j = 0;
		map->str[i] = ft_strnew(size);
		while (j < size)
		{
			map->str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}