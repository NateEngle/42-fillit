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
#include <stdio.h>

int	valid_nums(char *map)
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

// int compare_shapes(char **tet, char **shapes)
// {
// 	int pound;
// 	int i;
	
// }
int find_like(char **shapes, int holder)
{
	int i;

	i = 0;
	while (shapes[i] != shapes[holder])
		i++;
	return (i);
}

int confirm_pound(char *tet, int j)
{
	int i;

	i = 0;
	if (j < 5)
		return (0);
	while (tet[i] != '#')
		i++;
	return (j - i);
	
}
// int pound_num(char **shapes, int x, int y)
// {
// 	int pound;

// 	pound = 4
// 	if (shapes[x][y] == '#')
// 	{
		
// 	}
// }
int type_block(char *tet, char **shapes)
{
	int i;
	int j;
	int x;
	int y;
	int pound;

	i = 0;
	x = 0;
	pound = 4;
    j = 0;
	while (tet[j] && shapes[x] && pound != 0)
    {
		if (tet[j] == '#')
		{
			y = confirm_pound(tet, j);
			if (shapes[x][y] == '#')
				pound--;
			else
			{
				x++;
				j = -1;
				y = 0;
				pound = 4;
			}
		}
		j++;
	}
	if (tet[j] == '\0' && pound != 0)
		x++;
	if (tet[j] == '\0' && shapes[x] == '\0')
		return (-1);
	return (find_like(shapes, x));
}

int main()
{
	int enu;
	char *change1;
	char *change2;
	char **copy1;
	char **copy2;
	char *tetriminos[23] = {"....\n..#.\n..#.\n.##."};
	
	char check1[] = "##..\n.#..\n.#..\n....\n";
	char check2[] = "#..\n.#..\n##..\n....";
	change1 = check1;
	change2 = check2;
	char *check[23] = { change1, change2};

	copy1 = tetriminos;
	copy2 = check;
	enu = type_block(copy1[0], copy2);
	printf("%s\n\n", copy1[0]);
	printf("%s\n", check1);
	printf("%s\n", check2);
	printf("%d\n", enu);
	return (0);
}


// int main()
// {
//     int i = 0;
//     char **new;
//     char **cpy;
//     char ell[] = ".#..\n.#..\n.##.\n....";
//     char sq[] = ".##.\n.##.\n....\n....";
//     char tall[] = "#...\n#...\n#...\n#...";
//     char zee[] = "....\n..#.\n..##\n...#";
//     char bell[] = "#...\n###.\n....\n....";
//     char tri[] = "....\n.#..\n###.\n....";
//     char *cell;
//     char *csq;
//     char *ctall;
//     char *czee;
//     char *cbell;
//     char *ctri;

//     cell = ell;
//     csq = sq;
//     ctall = tall;
//     czee = zee;
//     cbell = bell;
//     ctri = tri;
//     char *str[23] = { cell, csq, ctall, czee, cbell, ctri };

//     cpy = str;
//     // printf("%s\n\n", cpy[0]);
//     // printf("%s\n\n", cpy[1]);
// 	// printf("%s\n\n", cpy[2]);
//     // printf("%s\n\n", cpy[3]);
//     // printf("%s\n\n", cpy[4]);
//     // printf("%s\n\n", cpy[5]);
// 	if (!check_valid(cpy))
// 	{
// 		printf("error\n");
// 		return (0);
// 	}
//     new = make_letters(cpy);
// 	i = 0;
//     while (new[i])
//     {
//         printf("%s\n\n", new[i]);
//         i++;
//     }
//     return (0);
// }
