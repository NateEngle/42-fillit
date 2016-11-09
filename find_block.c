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

static int find_like(char **shapes, int holder)
{
	int i;

	i = 0;
	while (shapes[i] != shapes[holder])
		i++;
	return (i);
}

static int confirm_pound(char *tet, int j)
{
	int i;

	i = 0;
	while (tet[i] != '#')
		i++;
	return (j - i);
	
}

static int pound_num(char **shapes, int x, int y, int pound)
{
	if (shapes[x][y] == '#')
		return ((pound - 1));
	else
		return (4);
}

int type_block(char *tet, char **shapes)
{
	int j;
	int x;
	int y;
	int pound;

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
	if (x == 19)
		return (-1);
	return (find_like(shapes, x));
}


// #include <stdio.h>
// int main()
// {
// 	int enu;

// 	char **copy1;
// 	char **copy2;
// 	char *tetriminos[2] = {"#...\n.#..\n..#.\n...#"};
	
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
