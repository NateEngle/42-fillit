/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:36:46 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/31 10:59:42 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			cnt_check(char *new)
{
	int		dot;
	int		pound;
	int		newline;

	dot = 0;
	newline = 0;
	pound = 0;
	while (*new)
	{
		if (*new == '.')
			dot++;
		else if (*new == '#')
			pound++;
		else if (*new == '\n')
			newline++;
		else
			return (0);
		new++;
	}
	if ((dot % 4 != 0) || (pound % 4 != 0) || (((newline + 1) % 5) != 0))
		return (0);
	return (1);
}

int			valid_nums(char *map)
{
	int		i;
	int		pound;
	int		empty;
	int		newline;

	i = 0;
	pound = 0;
	empty = 0;
	newline = 0;
	while (map[i])
	{
		if (map[i] == '#')
			pound++;
		else if (map[i] == '.')
			empty++;
		else if (map[i] != '\n')
			return (0);
		i++;
	}
	if (pound != 4 || empty != 12)
		return (0);
	return (1);
}

int			touching_tets(char *tet)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (tet[i] == '#')
		{
			if ((i - 1) >= 0 && tet[i - 1] == '#')
				count++;
			if ((i - 5) >= 0 && tet[i - 5] == '#')
				count++;
			if ((i + 1) < 19 && tet[i + 1] == '#')
				count++;
			if ((i + 5) < 19 && tet[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

int			check_valid(char **tets)
{
	int		i;

	i = 0;
	while (tets[i] != '\0')
	{
		if (!valid_nums(tets[i]) || !touching_tets(tets[i]))
			return (0);
		i++;
	}
	return (1);
}
