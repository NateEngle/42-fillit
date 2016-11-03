/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nengle- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 20:31:43 by nengle-           #+#    #+#             */
/*   Updated: 2016/10/30 19:12:43 by jcapling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
