/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:37:30 by nengle-           #+#    #+#             */
/*   Updated: 2016/12/03 19:37:32 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*read_funct(int fd)
{
	int i;
	t_list	*list;
	char	*buf;
	char	val;
	t_piece	*piece;

	val = 'A';
	buf = ft_strnew(21);
	list = NULL;
	while ((i = read(fd, buf, 21) >= 20))
	{
		if (valid_tet(buf, i) != 0 || (piece = get_piece(buf, val++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (delete_list(list));
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_piece)));
		ft_memdel((void **)&piece);
	}
	ft_memdel((void **)&buf);
	if (i != 0)
		return (delete_list(list));
	ft_lstrev(&list);
	return (list);
}

int		valid_tet(char *buf, int cnt)
{
	int	i;
	int	piece;

	i = 0;
	piece = 0;
	while (i < 20)
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (1);
		if (buf[i] == '#' && piece++ > 4)
			return (2);
		i++;
	}
	if (cnt == 21 && buf[20] != '\n')
		return (3);
	if (!tet_touch(buf))
		return (4);
	return (0);
}

int			tet_touch(char	*buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				count++;
			if ((i + 1) < 19 && buf[i + 1] == '#')
				count++;
			if ((i + 5) < 19 && buf[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count == 6 || count == 8);
}

char *reading(char *file)
{
	int	fd;
	int	i;
	int	ret;
	char tmp[545];
	char buf[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putstr("error\n");
	while ((ret = read(fd, buf, 1)) != 0)
	{
		tmp[i] = buf[0];
		i++;
		if (i > 545)
			ft_putstr("error\n");
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_putstr("error\n");
	return (ft_strdup(tmp));
}

int cnt_check(char *str)
{
	char	*new;
	int		dot;
	int		pound;
	int		newline;

	dot = 0;
	newline = 0;
	pound = 0;
	new = reading(str);
	while (*new)
	{
		if (*new == '.')
			dot++;
		else if (*new == '#')
			pound++;
		else if (*new == '\n')
			newline++;
		else
			return (0);
		new++;
	}
	if ((dot % 4 != 0) && (pound % 4 != 0) && (((newline + 1) % 5) != 0))
		return (0);
	return (1);
}