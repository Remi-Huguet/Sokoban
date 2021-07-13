/*
** EPITECH PROJECT, 2021
** move
** File description:
** move
*/
#include "../include/sokoban.h"

int move_up(char **map, int lgs, int tempo)
{
    if (map[lgs - 1][tempo] == 'X') {
        if (lgs - 2 < 0)
            return (0);
        if (map[lgs - 2][tempo] == '#' || map[lgs - 2][tempo] == 'X')
            return (0);
        map[lgs - 2][tempo] = 'X';
        map[lgs - 1][tempo] = 'P';
        map[lgs][tempo] = ' ';
    }
    map[lgs][tempo] = ' ';
    map[lgs - 1][tempo] = 'P';
    return (0);
}

int move_down(char **map, int lgs, int tempo)
{
    int i = 0;

    while (map[i])
        i = i + 1;
    if (map[lgs + 1][tempo] == 'X') {
        if (lgs + 2 > i - 1)
            return (0);
        if (map[lgs + 2][tempo] == '#' || map[lgs + 2][tempo] == 'X')
            return (0);
        map[lgs + 2][tempo] = 'X';
        map[lgs + 1][tempo] = 'P';
        map[lgs][tempo] = ' ';
    }
    map[lgs][tempo] = ' ';
    map[lgs + 1][tempo] = 'P';
    return (0);
}

int move_right(char **map, int lgs, int tempo)
{
    if (map[lgs][tempo - 1] == 'X') {
        if (tempo - 2 < 0)
            return (0);
        if (map[lgs][tempo - 2] == '#' || map[lgs][tempo - 2] == 'X')
            return (0);
        map[lgs][tempo - 2] = 'X';
        map[lgs][tempo - 1] = 'P';
        map[lgs][tempo] = ' ';
    }
    map[lgs][tempo] = ' ';
    map[lgs][tempo - 1] = 'P';
    return (0);
}

int move_left(char **map, int lgs, int tempo)
{
    if (map[lgs][tempo + 1] == 'X') {
        if (tempo + 2 > my_strlen(map[lgs]) - 1)
            return (0);
        if (map[lgs][tempo + 2] == '#' || map[lgs][tempo + 2] == 'X')
            return (0);
        map[lgs][tempo + 2] = 'X';
        map[lgs][tempo + 1] = 'P';
        map[lgs][tempo] = ' ';
    }
    map[lgs][tempo] = ' ';
    map[lgs][tempo + 1] = 'P';
    return (0);
}

int get_pos(char **map, int *lgs, int *tempo)
{
    int cls = 0;
    int i = 0;

    while (map[*lgs] && i == 0) {
        while (map[*lgs][cls] != '\0' && map[*lgs][cls] != '\n' && i == 0) {
            is_p(map[*lgs][cls], &i);
            cls = cls + 1;
        }
        *tempo = cls;
        cls = 0;
        *lgs = *lgs + 1;
    }
    *tempo = *tempo - 1;
    *lgs = *lgs - 1;
    return (0);
}
