/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:26:12 by nengle-           #+#    #+#             */
/*   Updated: 2016/11/04 20:26:14 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *printables(int enums)
{
    char *prints[20] = {"#...\n#...\n##",
"##..\n.#..\n.#",
"#.\n###",
"###.\n#",
"##..\n#...\n#",
"###.\n..#",
"#..\n.#..\n##",
"#...\n###",
"##..\n##",
"#...\n#...\n#...\n#",
"####",
"##..\n.##",
"#..\n##..\n#",
"##.\n##",
"#...\n##..\n.#",
"#..\n###",
"#...\n##..\n#",
"###.\n.#",
"#..\n##..\n.#"};
    return (prints[enums]); 
}

// char **putblock(char **map, char **block)
// {
//     int i;
//     int j;

//     int i = 0
//     int j = 0;
//     while (block)
//     (
//     	while (*block)
// 		{
// 			if (ft_isupper(**block) || **block == '\n')
// 				ft_putchar(**block);
// 			if (**block == ".")
// 				ft_putchar(' ');
// 			**block++;
// 		}
// 		*block++;
//     )
// 	while (map)

// }

