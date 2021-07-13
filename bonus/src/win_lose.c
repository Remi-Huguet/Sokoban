/*
** EPITECH PROJECT, 2021
** win_lose
** File description:
** win_lose
*/
#include <ncurses.h>

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

int x_on_o(int i, int y, int *coord_O)
{
    int x = 0;

    while (coord_O[x] != -10) {
        if (coord_O[x] == i && coord_O[x + 1] == y)
            return (0);
        x = x + 2;
    }
    return (-1);
}

int check(char **map, int i, int y, int *coord_O)
{
    if (map[i][y] == 'X')
        if (is_blocked(map, i, y) == 0 && \
x_on_o(i, y, coord_O) == -1)
            return (0);
    return (1);
}

int lose(char **map, int *coord_O)
{
    int i = 0;
    int y = 0;
    int rt = 1;

    while (map[i]) {
        while (map[i][y] != '\0' && map[i][y] != '\n' && rt != 0) {
            rt = check(map, i, y, coord_O);
            y = y + 1;
        }
        if (rt == 0) {
            y = y - 1;
            return (0);
        }
        i = i + 1;
        y = 0;
    }
    return (-1);
}
