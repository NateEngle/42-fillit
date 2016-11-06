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
#include <stdio.h>

int		block_num(char *holder)
{
	int x;
	int count;

	x = 0;
	count = 0;
	while (holder[x])
	{
		if((holder[x] == '\n' && holder[x + 1] == '\n'))
			count++;
		x++;
	}
	if (holder[x] == '\0')
		count++;
	return (count);
}
char **split_input(char *map)
{
	char *holder;
	char **output;
	int count;
	int i;
	int itero;

	i = 0;
	count = 0;
	itero = 0;
	holder = map;
	count = block_num(holder);
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

int 		max_num(char **map)
{
	int 	i;
	int 	max_num;

	i = 0;
	max_num = 2;
	while (map[i] != '\0')
		i++;
	while (max_num * max_num < i * 4)
		max_num++;
	return (max_num);
}

// int main()
// {
// 	char **this;
// 	int i;

// 	i = 0;
// 	this = split_input(".##.\n##..\n....\n....\n\n##..\n#...\n#...\n....");
// 	while (this[i])
// 	{
// 		printf("this is index: %d\n%s\n", i, this[i]);
// 		i++;
// 	}
// 	free (this);
// 	return (0);
// }






// ELL;
// "#...\n#...\n##..\n....";
// "##..\n.#..\n.#..\n....";
// "#.\n###.\n....\n....";
// "###.\n#...\n....\n....";

// B-Ell;
// "##..\n#...\n#...\n....";
// "###.\n...#\n....\n....";
// "#..\n.#..\n##..\n....";
// "#...\n###.\n....\n....";

// SQ;
// "##..\n##..\n....\n....";

// TALL;
// "#...\n#...\n#...\n#...";
// "####\n....\n....\n....";

// ZEE;
// "##..\n.##.\n....\n....";
// "#..\n##..\n#...\n....";

// B-ZEE;
// "##.\n##..\n....\n....";
// "#...\n##..\n.#..\n....";

// TRI;
// "#..\n###.\n....\n....";
// "#...\n##..\n#...\n....";
// "###.\n.#..\n....\n....";
// "#..\n##..\n.#..\n....";

// enum tetriminos
// {
//     ell0,
//     ell1,
//     ell2,
//     ell3,
//     square,
//     tall0,
//     tall1,
//     zee0,
//     zee1,
//     bzee0,
//     bzee1,
//     bell0,
//     bell1,
//     bell2,
//     bell3,
//     tri0,
//     tri1,
//     tri2,
//     tri3
// };

