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
#include <unistd.h>

int end_game(int i)
{
    usleep(500000);
    curs_set(true);
    endwin();
    if (i == 0)
        return (0);
    return (1);
}

void init_all(char **map, int *coord_O, int nb)
{
    get_all_coord(map, coord_O);
    curs_set(false);
    keypad(stdscr, TRUE);
    my_put_map(map, coord_O, nb);
    refresh();
}

int play(char **map, int *coord_O, int i, int *nb)
{
    if (i == 27)
        select_map("");
    move_player(map, i, &nb);
    reset_o(map, coord_O);
    my_put_map(map, coord_O, *nb);
    refresh();
    return (0);
}

int my_sokoban(char **map, int nb_O, char *to_reset, int nb)
{
    int i = 0;
    int coord_O[nb_O * 2];
    int tempo = nb;

    init_all(map, coord_O, nb);
    while (map) {
        if (win(map, coord_O) == 0)
            select_map("win");
        if (lose(map, coord_O) == 0 || nb <= 0)
            select_map("lose");
        i = getch();
        clear();
        if (i == 32)
            return (map_in_double_char(to_reset, nb_O, tempo));
        play(map, coord_O, i, &nb);
    }
    endwin();
    return (0);
}

int map_in_double_char(char *map, int nb_O, int nb)
{
    int rt = 0;
    char **double_map = malloc(sizeof(char) * my_strlen(map));

    double_map = my_str_to_word_array(map);
    rt = my_sokoban(double_map, nb_O, map, nb);
    free(double_map);
    if (rt == 84)
        return (84);
    return (rt);
}
