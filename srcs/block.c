/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:36:40 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:36:42 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		*new_coord(int x, int y)
{
	t_coord	*coord;

	coord = (t_coord *)ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

t_piece		*new_piece(char **place, int width, int height, char value)
{
	t_piece	*piece;

	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	piece->place = place;
	piece->width = width;
	piece->height = height;
	piece->value = value;
	return (piece);
}

void	delete_piece(t_piece  *piece)
{
	int i;

	i = 0;
	while (i < piece->height)
	{
		ft_memdel((void **)(&(piece->place[i])));
		i++;
	}
	ft_memdel((void **)(&(piece->place)));
	ft_memdel((void **)&piece);
}

t_list	*delete_list(t_list *list)
{
	t_piece *piece;
	t_list *next;

	while (list)
	{
		piece = (t_piece *)list->content;
		next = list->next;
		delete_piece(piece);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
