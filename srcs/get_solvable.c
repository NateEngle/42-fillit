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

int get_width(int k)
{
	int width[19];
	
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

int get_height(int k)
{
		int height[19];
	
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
char *get_places(int k)
{
	char *places[19];
	
	places[0] = "# # ##";
	places[1] = "## # #";
	places[2] = "  ####";
	places[3] = "####";
	places[4] = "### # ";
	places[5] = "###  #";
	places[6] = " # ###";
	places[7] = "#  ###";
	places[8] = "####";
	places[9] = "####";
	places[10] = "####";
	places[11] = "##  ##";
	places[12] = " #### ";
	places[13] = " #### ";
	places[14] = "# ## #";
	places[15] = " # ###";
	places[16] = "# ### ";
	places[17] = "### # ";
	places[18] = " ### #";
	return (places[k]);
}

char **get_dblchar(char *split)
{
	int k;
	char **new;
	char *check[19] = {"#...\n#...\n##..\n....", "##..\n.#..\n.#..\n....",
		"#.\n###.\n....\n....", "###.\n#...\n....\n....",
		"##..\n#...\n#...\n....", "###.\n..#.\n....\n....",
		"#..\n.#..\n##..\n....", "#...\n###.\n....\n....",
		"##..\n##..\n....\n....", "#...\n#...\n#...\n#...",
		"####\n....\n....\n....", "##..\n.##.\n....\n....",
		"#..\n##..\n#...\n....", "##.\n##..\n....\n....",
		"#...\n##..\n.#..\n....", "#..\n###.\n....\n....",
		"#...\n##..\n#...\n....", "###.\n.#..\n....\n....",
		"#..\n##..\n.#..\n...."};
	if ((k = type_block(split, check)) == -1)
		return (NULL);
	new = get_charstr(get_places(k), get_width(k), get_height(k));
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
