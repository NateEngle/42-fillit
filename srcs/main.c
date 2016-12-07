/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:36:47 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:36:49 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit Input_file\n");
		return (1);
	}
	if ((list = read_funct(open(av[1], O_RDONLY))) == NULL || !cnt_check(av[1]))
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solver(list);
	printf("%s\n", "BOOB");
	print_map(map);
	printf("%s\n", "BUTTS");
	delete_map(map);
	printf("%s\n", "BALLZ");
	delete_list(list);
	printf("%s\n", "BRAINS");
	return (0);
}
