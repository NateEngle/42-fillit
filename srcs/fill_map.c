/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:44:12 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/04 18:44:28 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**make_map(int max_num)
{
	int		x;
	int		y;
	char	**str;

	y = 0;
	while (!(str = (char **)malloc(sizeof(char *) * (max_num + 1))))
		return (NULL);
	while (y < max_num)
	{
		str[y] = ft_strnew(max_num);
		x = 0;
		while (x < max_num)
		{
			str[y][x] = '.';
			x++;
		}
		y++;
	}
	str[y] = NULL;
	return (str);
}

char		**solver(char ***group, int count)
{
	int		k;
	int		size;
	char	**map;

	k = -1;
	size = max_num(count);
	map = make_map(size);
	while (!(fillit_solve(group, ++k, map, size)))
	{
		size++;
		delete_map(map);
		map = make_map(size);
		k = -1;
	}
	return (map);
}

int			fillit_solve(char ***total, int k, char **map, int size)
{
	int		i;
	int		j;
	int		c;
	int		d;

	i = 0;
	if (total[k] == NULL)
		return (1);
	while (i < size - (c = tet_height(total[k])) + 1)
	{
		j = 0;
		while (j < size - (d = tet_width(total[k])) + 1)
		{
			if (place_tet(total[k], map, j, i))
			{
				if (fillit_solve(total, k + 1, map, size))
					return (1);
				else
					convert_to_dot(total[k], map, j, i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
