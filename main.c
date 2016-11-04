/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 23:02:34 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/30 19:09:34 by jcapling         ###   ########.fr       */
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
		output[itero] = ft_strsub(holder, i, 19);
		itero++;
		count--;
		i = i + 21;
	}
	output[itero] = NULL;
	return (output);
}

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

int pound_num(char **shapes, int x, int y, int pound)
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
	if (tet[j] == '\0' || x == 19)
		return (-1);
	return (find_like(shapes, x));
}

char *read_file(char *file)
{
	int ret;
	int fd;
	char tmp[545];
	char buf[1];
	int i;
	
	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putstr("error\n");
	while ((ret = read(fd, buf, 1)))
	{
		tmp[i++] = buf[0];
		if (i > 545)
			ft_putstr("error\n");
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_putstr("error\n");
	return (ft_strdup(tmp));
}

void	ft_error()
{
	// int i;
	// char **tetriminos;

	// while (tetriminos[i])
	// {
	// 	if (!check_valid(&tetriminos[i]))
	// 	{
			ft_putstr("error\n");
			exit (0);
	// 	}
	// 	i++;
	// }
	// return (1);
}

int 	main(int ac, char **av)
{
	char *reader;
	char **map;
	int i;

	i =0;
	if (ac != 2)
		ft_error();
	reader = read_file(av[1]);
	printf("%s\n", reader);
	if (type_block(reader, check) == -1)
		ft_error();
	map = split_input(reader);
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	// while (map[i])
	// {
	// 	printf("%s\n\n", map[i]);
	// 	free(*(map + i));
	// 	i++;
	// }
	free(map);
	
	return (0);
}

	// while (map[i])
	// {
		
	// }
	// printf("%s\n", map[0]);
	// printf("%s\n", map[1]);
	// printf("%s\n", map[2]);
	// // while (map[i])
	// // {
	// // 	printf("%s\n\n", map[i]);
	// // 	free(*(map + i));
	// // 	i++;
	// // }
	// free(map);
