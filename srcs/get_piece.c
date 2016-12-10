/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:29:37 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/04 22:29:39 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*get_piece(char *buf, char value)
{
	int i;
	t_coord	*min;
	t_coord	*max;
	t_piece	*piece;
	char	**place;

	i = 0;
	min = new_coord(3,3);
	max = new_coord(0,0);
	max_coord(buf, min, max);
	place = (char **)ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while (i < max->y - min->y + 1)
	{
		place[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(place[i], buf + (min->x) + (i + min->y) * 5,
			max->x - min->x + 1);
		i++;
	}
	piece = new_piece(place, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (piece);
}

void	max_coord(char *str, t_coord *min, t_coord *max)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i / 5) < min->y)
				min->y = (i / 5);
			if ((i % 5) < min->x)
				min->x = (i % 5);
			if ((i / 5) > max->y)
				max->y = (i / 5);
			if ((i % 5) > max->x)
				max->x = (i % 5);
		}
		i++;
	}
}