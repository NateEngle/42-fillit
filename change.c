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
<<<<<<< HEAD

// int main()
// {
//     int i = 0;
//     char **new;
//     char **cpy;
//     char ell[] = ".#..\n.#..\n.##.\n....";
//     char sq[] = ".##.\n.##.\n....\n....";
//     char tall[] = "#...\n#...\n#...\n#...";
//     char zee[] = "....\n..#.\n..##\n...#";
//     char bell[] = "#...\n###.\n....\n....";
//     char tri[] = "....\n.#..\n###.\n....";
//     char *cell;
//     char *csq;
//     char *ctall;
//     char *czee;
//     char *cbell;
//     char *ctri;

//     cell = ell;
//     csq = sq;
//     ctall = tall;
//     czee = zee;
//     cbell = bell;
//     ctri = tri;
//     char *str[23] = { cell, csq, ctall, czee, cbell, ctri };

//     cpy = str;
//     printf("%s\n\n", cpy[0]);
//     printf("%s\n\n", cpy[1]);
// 	printf("%s\n\n", cpy[2]);
//     printf("%s\n\n", cpy[3]);
//     printf("%s\n\n", cpy[4]);
//     printf("%s\n\n", cpy[5]);
//     new = make_letters(cpy);
//     while (new[i])
//     {
//         printf("%s\n\n", new[i]);
//         i++;
//     }
//     return (0);
// }

=======
>>>>>>> dd4ddf496f0d3e19bc700f8b9946cc81d056333f
