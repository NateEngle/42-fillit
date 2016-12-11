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

#include "header.h"

static int	valid_nums(char *map)
{
	int i;
	int pound;
	int empty;

	i = 0;
	pound = 0;
	empty = 0;
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
	if (pound != 4)
		return (0);
	if (empty != 12)
		return (0);
	return (1);
}

int	check_valid(char **tetriminos)
{
    int i;

    i = 0;
    while (tetriminos[i] != '\0')
    {   
        if(!(valid_nums(tetriminos[i])))
            return (0);
        i++;
    }
    return (1);
}

int tet_width(char **tet)
{
	int i;
	int j;
	int hold;
	int width;

	i = 0;
	hold = -1;
	while (tet[i] != '\0')
	{
		j = 0;
		width = 0;
		while (tet[i][j] != '\0')
		{
			if (ft_isupper(tet[i][j]))
				width++;
			j++;
		}
		if (width >= hold)
			hold = width;
		i++;
	}
	return (hold);
}

int tet_height(char **tet)
{
	int i;
	int j;
	int hold;
	int height;

	i = 0;
	hold = -1;
	while (tet[i] != '\0')
	{
		j = 0;
		height = 0;
		while (tet[i][j] != '\0')
		{
			if (ft_isupper(tet[i][j]))
			{
				height++;
				j = 3;
			}
			j++;
		}
		if (height >= hold)
			hold = height;
		i++;
	}
	return (hold);
}
// #include <stdio.h>
// int main()
// {
// 	int enu;
// 	char *change1;
// 	char *change2;
// 	char **copy1;
// 	char **copy2;
// 	char *tetriminos[23] = {"#...\n.#..\n..#.\n...#"};
	
// 	char check1[] = "#..\n.#..\n##..\n....\n";
// 	char check2[] = "##..\n.#..\n.#..\n....\n";
// 	change1 = check1;
// 	change2 = check2;
// 	char *check[23] = { "#...\n#...\n##..\n....",
// 	"##..\n.#..\n.#..\n....",
// 	"#.\n###.\n....\n....",
// 	"###.\n#...\n....\n....",
// 	"##..\n#...\n#...\n....",
// 	"###.\n...#\n....\n....",
// 	"#..\n.#..\n##..\n....",
// 	"#...\n###.\n....\n....",
// 	"##..\n##..\n....\n....",
// 	"#...\n#...\n#...\n#...",
// 	"####\n....\n....\n....",
// 	"##..\n.##.\n....\n....",
// 	"#..\n##..\n#...\n....",
// 	"##.\n##..\n....\n....",
// 	"#...\n##..\n.#..\n....",
// 	"#..\n###.\n....\n....",
// 	"#...\n##..\n#...\n....",
// 	"###.\n.#..\n....\n....",
// 	"#..\n##..\n.#..\n...."};

// 	copy1 = tetriminos;
// 	copy2 = check;
// 	enu = type_block(copy1[0], copy2);
// 	printf("%s\n\n", copy1[0]);
// 	printf("%d\n", enu);
// 	printf("%s\n", check[enu]);
// 	return (0);
// }
