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
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int             diff;
    unsigned char   *s12;
    unsigned char   *s22;

    s12 = (unsigned char *)s1;
    s22 = (unsigned char *)s2;
    diff = 0;
    while (n > 0 && (*s12 || *s22))
    {
        diff = *s12 - *s22;
        if (diff == 0)
        {
            s12++;
            s22++;
        }
        else
            return (diff);
        n--;
    }
    return (diff);
}

int type_block(char **tetriminos, char **shapes)
{
	int i;
	int j;
	int pound;
	int check;
	
	i = 0;
	pound = 4;
	while (tetriminos[i])
	{
    	j = 0;
    	if (tetriminos[i][j] == '#')
		{
			while (check != 0)
			{
				shapes++;
			}
			tetriminos[i]++;
		}
		i++;
	}
	i = 0;
	while (shapes[i] != *shapes)
		i++;
	return (i);
}

#include <stdio.h>

int main()
{
	int enu;
	char *check1;
	char *check2;
	char **check;
	char **copy1;
	char **copy2;
	char **tetriminos;

	tetriminos[0] = "....\n..#.\n..#.\n.##.";
	
	check1 = "#...\n#...\n##..\n....";
	check2 = "##..\n.#..\n.#..\n....";
	check = { chekc1, check2};

	copy1 = tetriminos;
	copy2 = check;
	enu = type_block(copy1, copy2);
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
