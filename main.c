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

void	ft_error(void)
{
<<<<<<< HEAD
	int i;
	char *tetriminos;
	char **map;

	tetriminos = ft_strsplit(read_file(av[1]), \n\n);
	while (tetriminos[i])
	{
		if (!check_valid(tetriminos[i]))
		{
			ft_putstr("error\n");
			return (0);
		}
		i++;
	}

	map = make_map(tetriminos);
=======
	write(1, "error\n", 6);
	exit (0);
}

int 	main(int ac, char **av)
{
	//char *tetriminos;
//	char **map;

	(void)ac;
	(void)av;

//	tetriminos = read_file(av[1]);
//	if (!check_valid(tetriminos))
//	{
//		ft_putstr("error\n");
//		return (0);
//	}
//	map = make_map(tetriminos);
>>>>>>> dd4ddf496f0d3e19bc700f8b9946cc81d056333f
	
	
	return (0);
}

