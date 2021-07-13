/*
** EPITECH PROJECT, 2021
** putw
** File description:
** putw
*/
#include "../include/sokoban.h"
#include <ncurses.h>

int too_small(char **map)
{
    char *msg = "TOO SMALL";
    int x = (LINES / 2);
    int y = (COLS / 2) - (my_strlen(msg) / 2);

    if (LINES <= (get_lgs(map) + 5) || COLS <= (my_strlen(map[0]) + 5)) {
        mvprintw(x, y, "%s", msg);
        return (1);
    }
    return (0);
}

void my_put_map(char **map)
{
    int x = (LINES / 2) - (get_lgs(map) / 2);
    int y = (COLS / 2) - (my_strlen(map[0]) / 2);
    int i = 0;

    if (too_small(map) == 0)
        while (map[i]) {
            mvprintw(x, y, "%s", map[i]);
            x = x + 1;
            i = i + 1;
        }
}
