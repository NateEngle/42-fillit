/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 20:31:43 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/30 19:12:43 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_change_char(char *tet, char alpha)
{
	int		i;

	i = 0;
	while (tet[i] != '\0')
	{
		if (tet[i] == '#')
			tet[i] = alpha;
		i++;
	}
	return (tet);
}

char		***make_letters(char ***tet)
{
	char	alpha;
	char	***cpy;
	int		i;
	int		j;

	i = 0;
	alpha = 'A';
	cpy = tet;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			cpy[i][j] = ft_change_char(cpy[i][j], alpha);
			j++;
		}
		i++;
		alpha++;
	}
	return (cpy);
}

int			place_tet(char **piece, char **map, int x, int y)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	z = 0;
	while (i < tet_width(piece))
	{
		j = 0;
		while (j < tet_height(piece))
		{
			if (ft_isupper(piece[j][i]) && map[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	convert_tet(piece, map, x, y);
	return (1);
}

void		convert_tet(char **piece, char **map, int x, int y)
{
	int		i;
	int		j;
	int		z;
	char	value;

	i = 0;
	z = 0;
	while (!(ft_isupper(piece[0][z])))
		z++;
	value = piece[0][z];
	while (i < tet_width(piece))
	{
		j = 0;
		while (j < tet_height(piece))
		{
			if (ft_isupper(piece[j][i]))
				map[y + j][x + i] = value;
			j++;
		}
		i++;
	}
}

void		convert_to_dot(char **piece, char **map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tet_width(piece))
	{
		j = 0;
		while (j < tet_height(piece))
		{
			if (ft_isupper(piece[j][i]))
				map[y + j][x + i] = '.';
			j++;
		}
		i++;
	}
}
