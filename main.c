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
	// char **holder = NULL;


	i =  0;
	// int val;
	if (ac != 2)
		ft_putstr("usage: ./fillit input_file");
	reader = read_file(av[1]);
	// if ((val = type_block(reader, check)) == -1)
	// 	ft_error();
	// printf("%d\n", val);

	// if (get_coords(reader) == -1)
	// 	ft_error();
	count = block_num(reader);
	places = split_input(reader, count);
	ft_memdel((void **)&reader);
	char ***y = group_tets(places, count);
	int j = 0;
	int k;
	while (y[j])
	{
		k = 0;
		while (y[j][k])
		{
			ft_putstr(y[j][k]);
			ft_putchar('\n');
			k++;
		}
		j++;
	}
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

	// char *blah = "#\n#\n##\n";
	// ft_putstr(blah);
	// ft_putchar('\n');
	// char *blah2 = "##\n #\n #\n";
	// ft_putstr(blah2);
	// ft_putchar('\n');
	// char *blah3 = "  #\n###\n";
	// ft_putstr(blah3);
	// ft_putchar('\n');
	// char *blah4 = "###\n#\n";
	// ft_putstr(blah4);
	// ft_putchar('\n');
	// char *blah5 = "##\n#\n#\n";
	// ft_putstr(blah5);
	// ft_putchar('\n');
	// char *blah6 = "###\n  #\n";
	// ft_putstr(blah6);
	// ft_putchar('\n');
	// char *blah7 = " #\n #\n##\n";
	// ft_putstr(blah7);
	// ft_putchar('\n');
	// char *blah8 = "#\n###\n";
	// ft_putstr(blah8);
	// ft_putchar('\n');
	// char *blah9 = "##\n##\n";
	// ft_putstr(blah9);
	// ft_putchar('\n');
	// char *blah10 = "#\n#\n#\n#\n";
	// ft_putstr(blah10);
	// ft_putchar('\n');
	// char *blah11 = "####\n";
	// ft_putstr(blah11);
	// ft_putchar('\n');
	// char *blah12 = "##\n ##\n";
	// ft_putstr(blah12);
	// ft_putchar('\n');
	// char *blah13 = " #\n##\n#\n";
	// ft_putstr(blah13);
	// ft_putchar('\n');
	// char *blah14 = " ##\n##\n";
	// ft_putstr(blah14);
	// ft_putchar('\n');
	// char *blah15 = "#\n##\n #\n";
	// ft_putstr(blah15);
	// ft_putchar('\n');
	// char *blah16 = " #\n###\n";
	// ft_putstr(blah16);
	// ft_putchar('\n');
	// char *blah17 = "#\n##\n#\n";
	// ft_putstr(blah17);
	// ft_putchar('\n');
	// char *blah18 = "###\n#\n";
	// ft_putstr(blah18);
	// ft_putchar('\n');
	// char *blah19 = " #\n##\n#\n";
	// ft_putstr(blah19);
	// ft_putchar('\n');
	return (0);
}


