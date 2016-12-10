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
#include <stdio.h>

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
		while (!(fill_solve(group, k, map)))
		{
			printf("%s\n", "da");
			size++;
			ft_memdel((void **)&map);
			map = fill_blank(size);
			k = -1;
		}
		k++;
	}
	return (map);
}

int		fill_solve(char ***total, int k, char **map)
{
	int i;
	int j;

	i = 0;
	printf("%d\n", k);
	if (total[k] == NULL)
		return (1);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (place_tet(total[k], map, j, i))
			{
				if (fill_solve(total, k + 1, map))
					return (1);
				else
					convert_tet(total[k], &map, j, i, '.');
				printf("%s\n", "oui");
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