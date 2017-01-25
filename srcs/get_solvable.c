/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:24:54 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/09 14:24:57 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**get_charstr(char *buf, int width, int height)
{
	int		i;
	int		count;
	char	**new;

	i = 0;
	count = 0;
	new = (char **)ft_memalloc(sizeof(char *) * 5);
	while (i < height + 1)
	{
		new[i] = ft_strnew(5);
		ft_strncpy(new[i], buf + count, width + 1);
		i++;
		count = count + width + 1;
	}
	new[i] = NULL;
	return (new);
}

char		**get_dblchar(char *split)
{
	int		k;
	char	**new;
	char	*check[19];

	check[0] = "#...\n#...\n##..\n....";
	check[1] = "##..\n.#..\n.#..\n....";
	check[2] = "#.\n###.\n....\n....";
	check[3] = "###.\n#...\n....\n....";
	check[4] = "##..\n#...\n#...\n....";
	check[5] = "###.\n..#.\n....\n....";
	check[6] = "#..\n.#..\n##..\n....";
	check[7] = "#...\n###.\n....\n....";
	check[8] = "##..\n##..\n....\n....";
	check[9] = "#...\n#...\n#...\n#...";
	check[10] = "####\n....\n....\n....";
	check[11] = "##..\n.##.\n....\n....";
	check[12] = "#..\n##..\n#...\n....";
	check[13] = "##.\n##..\n....\n....";
	check[14] = "#...\n##..\n.#..\n....";
	check[15] = "#..\n###.\n....\n....";
	check[16] = "#...\n##..\n#...\n....";
	check[17] = "###.\n.#..\n....\n....";
	check[18] = "#..\n##..\n.#..\n....";
	return ((k = type_block(split, check)) == -1 ? NULL :
		(new = get_charstr(get_places(k), get_width(k), get_height(k))));
}

char		***group_tets(char **tet, int count)
{
	int		i;
	int		j;
	char	***group;

	i = 0;
	j = 0;
	group = (char ***)ft_memalloc(sizeof(char **) * (count + 1));
	while (i < count)
	{
		if ((group[i] = get_dblchar(tet[i])) == NULL)
			return (NULL);
		i++;
	}
	while (j < count)
	{
		ft_memdel((void **)&tet[j]);
		j++;
	}
	ft_memdel((void **)&tet);
	group[count] = NULL;
	return (group);
}
