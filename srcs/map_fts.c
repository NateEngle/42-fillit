/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:09:37 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/28 22:09:39 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**split_input(char *buf, int count)
{
	char	*holder;
	char	**output;
	int		i;
	int		itero;

	i = 0;
	itero = 0;
	holder = buf;
	if (!(output = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	while (count > 0)
	{
		if (!(output[itero] = ft_strsub(holder, i, 20)))
		{
			delete_map(output);
			return (NULL);
		}
		itero++;
		count--;
		i = i + 21;
	}
	output[itero] = NULL;
	ft_memdel((void **)&buf);
	return (output);
}

void		print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void		delete_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

int			max_num(int size)
{
	int		i;

	i = 2;
	size = size * 4;
	while (i * i < size)
		i++;
	return (i);
}
