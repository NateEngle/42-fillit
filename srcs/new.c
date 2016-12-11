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

#include "header.h"

int			block_num(char *holder)
{
	int		x;
	int		count;

	x = 0;
	count = 0;
	while (holder[x])
	{
		if ((holder[x] == '\n' && holder[x + 1] == '\n'))
			count++;
		x++;
	}
	if (holder[x] == '\0')
		count++;
	return (count);
}

char		**split_input(char *map, int count)
{
	char	*holder;
	char	**output;
	int		i;
	int		itero;

	i = 0;
	itero = 0;
	holder = map;
	if (!(output = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	while (count > 0)
	{
		output[itero] = ft_strsub(holder, i, 20);
		itero++;
		count--;
		i = i + 21;
	}
	output[itero] = NULL;
	return (output);
}
