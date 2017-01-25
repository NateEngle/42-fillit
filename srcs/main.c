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

#include "fillit.h"

char		*read_file(char *file)
{
	int		ret;
	int		fd;
	char	tmp[545];
	char	buf[1];
	int		i;

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

int			main(int ac, char **av)
{
	char	*reader;
	char	**places;
	int		count;
	char	**map;
	char	***y;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file");
		return (1);
	}
	reader = read_file(av[1]);
	count = block_num(reader);
	if (!cnt_check(reader) || (places = split_input(reader, count)) == NULL
		|| !check_valid(places))
	{
		ft_putstr("error\n");
		return (1);
	}
	y = group_tets(places, count);
	make_letters(y);
	map = solver(y, count);
	print_map(map);
	delete_map(map);
	return (0);
}
