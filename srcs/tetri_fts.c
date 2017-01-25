/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:01:25 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/10 21:01:27 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			tet_width(char **tet)
{
	int		i;
	int		j;
	int		hold;
	int		width;

	i = 0;
	hold = 0;
	while (tet[i] != '\0')
	{
		j = 0;
		width = 0;
		while (tet[i][j] != '\0')
		{
			if (ft_isupper(tet[i][j]) || tet[i][j] == '.')
				width++;
			j++;
		}
		if (width > hold)
			hold = width;
		i++;
	}
	return (hold);
}

int			tet_height(char **tet)
{
	int		i;
	int		j;
	int		height;
	int		check;

	i = 0;
	height = 0;
	while (tet[i] != '\0')
	{
		j = 0;
		check = height;
		while (tet[i][j] != '\0' && check == height)
		{
			if (ft_isupper(tet[i][j]))
				height++;
			j++;
		}
		i++;
	}
	return (height);
}

int			get_width(int k)
{
	int		width[19];

	width[0] = 1;
	width[1] = 1;
	width[2] = 2;
	width[3] = 2;
	width[4] = 1;
	width[5] = 2;
	width[6] = 1;
	width[7] = 2;
	width[8] = 1;
	width[9] = 0;
	width[10] = 3;
	width[11] = 2;
	width[12] = 1;
	width[13] = 2;
	width[14] = 1;
	width[15] = 2;
	width[16] = 1;
	width[17] = 2;
	width[18] = 1;
	return (width[k]);
}

int			get_height(int k)
{
	int		height[19];

	height[0] = 2;
	height[1] = 2;
	height[2] = 1;
	height[3] = 1;
	height[4] = 2;
	height[5] = 1;
	height[6] = 2;
	height[7] = 1;
	height[8] = 1;
	height[9] = 3;
	height[10] = 0;
	height[11] = 1;
	height[12] = 2;
	height[13] = 1;
	height[14] = 2;
	height[15] = 1;
	height[16] = 2;
	height[17] = 1;
	height[18] = 2;
	return (height[k]);
}

char		*get_places(int k)
{
	char	*places[19];

	places[0] = "#.#.##";
	places[1] = "##.#.#";
	places[2] = "..####";
	places[3] = "####";
	places[4] = "###.#.";
	places[5] = "###..#";
	places[6] = ".#.###";
	places[7] = "#..###";
	places[8] = "####";
	places[9] = "####";
	places[10] = "####";
	places[11] = "##..##";
	places[12] = ".####.";
	places[13] = ".####.";
	places[14] = "#.##.#";
	places[15] = ".#.###";
	places[16] = "#.###.";
	places[17] = "###.#.";
	places[18] = ".###.#";
	return (places[k]);
}
