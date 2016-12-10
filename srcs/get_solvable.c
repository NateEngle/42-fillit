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

#include "header.h"
#include <stdio.h>
char	**get_charstr(char *buf, int width, int height)
{
	int i;
	int count;
	char **new;

	i = 0;
	count = 0;
	new = (char **)ft_memalloc(sizeof(char *) * 5);
	while (i < height + 1)
	{
		new[i] = ft_strnew(4);
		ft_strncpy(new[i], buf + count, width + 1);
		i++;
		count = count + width + 1;
	}
	new[i] = NULL;
	return (new);
}

char **get_dblchar(char *split)
{
	int k;
	char **new;
	char *check[23] = {"#...\n#...\n##..\n....", "##..\n.#..\n.#..\n....",
		"#.\n###.\n....\n....", "###.\n#...\n....\n....",
		"##..\n#...\n#...\n....", "###.\n..#.\n....\n....",
		"#..\n.#..\n##..\n....", "#...\n###.\n....\n....",
		"##..\n##..\n....\n....", "#...\n#...\n#...\n#...",
		"####\n....\n....\n....", "##..\n.##.\n....\n....",
		"#..\n##..\n#...\n....", "##.\n##..\n....\n....",
		"#...\n##..\n.#..\n....", "#..\n###.\n....\n....",
		"#...\n##..\n#...\n....", "###.\n.#..\n....\n....",
		"#..\n##..\n.#..\n...."};
	int width[19] = {1, 1, 2, 2, 1, 2, 1, 2, 1, 0, 3, 2, 1, 2, 1, 2, 1, 2, 1};
	int height[19] = {2, 2, 1, 1, 2, 1, 2, 1, 1, 3, 0, 1, 2, 1, 2, 1, 2, 1, 2};
	char *places[20] = { "# # ##", "## # #", "  ####", "####",
		"### # ", "###  #", " # ###", "#  ###", "####",
		"####", "####", "##  ##", " #### ", " #### ",
		"# ## #", " # ###", "# ### ", "### # ", " ### #"};
	if ((k = type_block(split, check)) == -1)
		return (NULL);
	int this = tet_width(check[k]);
	printf("this is: %d\n", this);
	printf("width is: %d\n", width[k]);
	new = get_charstr(places[k], width[k], height[k]);
	return (new);
}

char	***group_tets(char **tet, int count)
{
	int i;
	int j;
	char ***group;

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
