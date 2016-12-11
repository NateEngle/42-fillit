/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:22:44 by nengle-           #+#    #+#             */
/*   Updated: 2016/11/02 20:22:50 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	find_like(char **shapes, int holder)
{
	int		i;

	i = 0;
	while (shapes[i] != shapes[holder])
		i++;
	return (i);
}

static int	confirm_pound(char *tet, int j)
{
	int		i;

	i = 0;
	while (tet[i] != '#')
		i++;
	return (j - i);
}

static int	pound_num(char **shapes, int x, int y, int pound)
{
	if (shapes[x][y] == '#')
		return ((pound - 1));
	else
		return (4);
}

int			type_block(char *tet, char **shapes)
{
	int		j;
	int		x;
	int		y;
	int		pound;

	x = 0;
	pound = 4;
	j = 0;
	while (tet[j] && shapes[x] && pound != 0)
	{
		if (tet[j] == '#')
		{
			y = confirm_pound(tet, j);
			pound = pound_num(shapes, x, y, pound);
			if (pound == 4)
			{
				x++;
				j = -1;
				y = 0;
			}
		}
		j++;
	}
	return (x == 19 ? (-1) : find_like(shapes, x));
}
