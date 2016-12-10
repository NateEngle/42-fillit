/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 23:02:34 by nengle-           #+#    #+#             */
/*   Updated: 2016/11/21 16:21:44 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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
	char **places;
	int i;
	int count;
	char **map;


	i =  0;
	if (ac != 2)
		ft_putstr("usage: ./fillit input_file");
	reader = read_file(av[1]);

	// if (get_coords(reader) == -1)
	// 	ft_error();
	count = block_num(reader);
	places = split_input(reader, count);
	ft_memdel((void **)&reader);
	printf("%d\n", count);
	char ***y = group_tets(places, count);
	make_letters(y);
	printf("%s\n", "yes");
	map = solver(y, count);
	printf("%s\n", "yes");
	int k;
	k = 0;
	printf("%s\n", "yes");
	while (map[k])
	{
		ft_putstr(map[k]);
		ft_putchar('\n');
		k++;
	}
printf("%s\n", "yes");
	// if (group_tets(places, count) == NULL)
	// 	ft_error();
	// size = max_num(holder);
	
	// while (places[i])
	// {
	// 	printf("%s\n", places[i]);
	// 	i++;
	// }

	// map = make_letters(map);


	// while (holder[i])
	// {
	//   	ft_putstr(holder[i]);
	//   	i++;
	// }
	// free(map);
	return (0);
}


