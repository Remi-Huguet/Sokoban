/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** my_sokoban
*/
#include "../include/sokoban.h"
#include <stdlib.h>
#include <stddef.h>
#include <ncurses.h>
#include <stdio.h>

void init_all(char **map, int *coord_O)
{
    get_all_coord(map, coord_O);
    initscr();
    curs_set(false);
    keypad(stdscr, TRUE);
    my_put_map(map);
    refresh();
}

int play(char **map, int *coord_O, int i)
{
    move_player(map, i);
    reset_o(map, coord_O);
    my_put_map(map);
    refresh();
    return (0);
}

int my_sokoban(char **map, int nb_O, char *to_reset)
{
    int i = 0;
    int coord_O[nb_O * 2];
    int rt = 2;

    init_all(map, coord_O);
    while (map) {
        rt = win_or_lose(map, coord_O);
        if (rt == 1 || rt == 0) {
            curs_set(true);
            endwin();
            return (rt);
        }
        i = getch();
        clear();
        if (i == 32)
            return (map_in_double_char(to_reset, nb_O));
        play(map, coord_O, i);
    }
    endwin();
    return (0);
}

int map_in_double_char(char *map, int nb_O)
{
    int rt = 0;
    char **double_map = malloc(sizeof(char) * my_strlen(map));

    double_map = my_str_to_word_array(map);
    rt = my_sokoban(double_map, nb_O, map);
    free(double_map);
    if (rt == 84)
        return (84);
    return (rt);
}
