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

#include "header.h"

char        **fill_blank(int max_num)
{
	int     x;
	int     y;
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

char **solver(char ***group, int count)
{
	int k;
	int size;
	char **map;

	k = 0;
	size = max_num(count);
	map = fill_blank(size);
	while (group[k])
	{
		while (!(fill_solve(group, k, map, size)))
		{
			size++;
			ft_memdel((void **)&map);
			map = fill_blank(size);
			k = -1;
		}
		k++;
	}
	return (map);
}

int		fill_solve(char ***total, int k, char **map, int size)
{
	int i;
	int j;
	int c;
	int d;

	i = 0;
	printf("%s\n", total[0][0]);
	if (total[k] == NULL)
		return (1);
	c = tet_height(total[k]);
	d = tet_width(total[k]);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("k = %d\n", k);
	printf("size = %d\n", size);
	while (i < size - (c = tet_height(total[k])) + 1)
	{
		j = 0;
		while (j < size - (d = tet_width(total[k])) + 1)
		{
			if (place_tet(total[k], map, j, i))
			{
				if (fill_solve(total, k + 1, map, size))
					return (1);
				else
					convert_tet(total[k], map, j, i, '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}

int 		max_num(int size)
{
	int		i;

	i = 2;
	size = size * 4;
	while (i * i < size)
		i++;
	return (i);
}