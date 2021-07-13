/*
** EPITECH PROJECT, 2021
** check_error
** File description:
** check_error
*/
#include "../include/sokoban.h"
#include <stdio.h>
#include <stdlib.h>

void count_carac(int *nb_P, int *nb_O, int *nb_X, char carac)
{
    if (carac == 'P')
        *nb_P = *nb_P + 1;
    if (carac == 'O')
        *nb_O = *nb_O + 1;
    if (carac == 'X')
        *nb_X = *nb_X + 1;
}

int check_error(char *map)
{
    int rt = 0;
    int i = 0;
    int nb_O = 0;
    int nb_X = 0;
    int nb_P = 0;

    while (map[i] != '\0') {
        if (map[i] != '#' && map[i] != 'O' && map[i] != '\n' && \
map[i] != 'P' && map[i] != 'X' && map[i] != ' ')
            return (84);
        count_carac(&nb_P, &nb_O, &nb_X, map[i]);
        i = i + 1;
    }
    if (nb_X != nb_O || nb_X == 0 || nb_P != 1)
        return (84);
    rt = map_in_double_char(map, nb_O);
    free(map);
    if (rt == 84)
        return (84);
    return (rt);
}

