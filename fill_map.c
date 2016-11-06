/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:44:12 by jcapling          #+#    #+#             */
/*   Updated: 2016/11/04 18:44:28 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char        **fill_blank(char **str, int max_num)
{
    int     x;
    int     y;

    y = 0;
    while (!(str = (char **)malloc(sizeof(char *) * (max_num + 1))))
        return (NULL);
    while (y < max_num)
    {
        str[y] = ft_strnew(max_num);
        x = 0;
        while (x < max_num)
        {
            str[y][x] = '.';
            x++;
        }
        y++;
    }
    str[y] = NULL;
    return (str);
}

char        **grab_tetri(char **str)
{
    int     i;
    int     k;
    int     j;
    char    **map = NULL;

    i = 0;
    j = 0;
    k = 0;
    while (str[i] != '\0')
    {
        if (str[i][k] == '#')
        {    
            map[j][k] = str[i][k];
            k++;
        }
        else
            k++;
        i++;
    }
    return (map);
}