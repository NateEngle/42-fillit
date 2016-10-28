/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 20:31:43 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/27 20:31:45 by nengle-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char *ft_change_pound(char *tet, char alpha)
{
    int  i;

    i = 0;
    while (tet[i] != '\0')
    {
        if (tet[i] == '#')
            tet[i] = alpha;
        i++;
    }
    return (tet);
}

char **make_letters(char **tet)
{
    char alpha;
    char    **cpy;
    int i;

    i = 0;
    alpha = 65;
    cpy = tet;
    while (cpy[i])
    {
        cpy[i] = ft_change_pound(cpy[i], alpha);
        i++;
        alpha++;
    }
    return (cpy);
}

int main()
{
    int i = 0;
    char **new;
    char **cpy;
    char one[] = ".#..\n.#..\n.##.\n....";
    char two[] = ".##.\n.##.\n....\n....";
    char *cpo;
    char *cpt;

    cpo = one;
    cpt = two;
    char *str[23] = { cpo, cpt };

    cpy = str;
    printf("%s\n\n", cpy[0]);
    printf("%s\n\n", cpy[1]);
    new = make_letters(cpy);
    while (new[i])
    {
        printf("%s\n\n", new[i]);
        i++;
    }
    return (0);
}
