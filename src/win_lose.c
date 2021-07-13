/*
** EPITECH PROJECT, 2021
** win_lose
** File description:
** win_lose
*/
#include "../include/sokoban.h"
#include <unistd.h>

int end_game(int i)
{
    usleep(500000);
    if (i == 0)
        return (0);
    return (1);
}

int win(char **map, int *coord_O)
{
    int i = 0;

    while (coord_O[i] != -10) {
        if (map[coord_O[i]][coord_O[i + 1]] != 'X')
            return (-1);
        i = i + 2;
    }
    return (0);
}

int is_blocked(char **map, int i, int y)
{
    int nb_wall = 0;

    if (map[i][y + 1] == '#')
        if (map[i + 1][y] == '#' || map[i - 1][y] == '#')
            nb_wall = nb_wall + 1;
    if (map[i][y - 1] == '#')
        if (map[i - 1][y] == '#' || map[i + 1][y] == '#')
            nb_wall = nb_wall + 1;
    if (map[i + 1][y] == '#')
        if (map[i][y - 1] == '#' || map[i][y + 1] == '#')
            nb_wall = nb_wall + 1;
    if (map[i - 1][y] == '#')
        if (map[i][y + 1] == '#' || map[i][y - 1] == '#')
            nb_wall = nb_wall + 1;
    if (nb_wall >= 2)
        return (0);
    return (-1);
}

int lose(char **map, int *coord_O)
{
    int i = 0;
    int nb_x = count_x(map);
    int tab[nb_x * 2];

    get_all_coor(map, tab);
    while (tab[i] != -10) {
        if (is_blocked(map, tab[i], tab[i + 1]) == -1)
            return (1);
        i = i + 2;
    }
    return (0);
}

int win_or_lose(char **map, int *coord_O)
{
    if (win(map, coord_O) == 0)
        return (end_game(0));
    if (lose(map, coord_O) == 0)
        return (end_game(1));
    return (2);
}
