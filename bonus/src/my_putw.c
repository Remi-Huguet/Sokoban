/*
** EPITECH PROJECT, 2021
** putw
** File description:
** putw
*/
#include "../include/sokoban.h"
#include <ncurses.h>

int get_longer(char **map)
{
    int i = 0;
    int longer = 0;

    while (map[i]) {
        if (my_strlen(map[i]) > my_strlen(map[longer]))
            longer = i;
        i = i + 1;
    }
    return (longer);
}

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

int count_o(char **map, int *coord_O)
{
    int i = 0;
    int nb_O = 0;

    while (coord_O[i] != -10) {
        if (map[coord_O[i]][coord_O[i + 1]] == 'P' || \
map[coord_O[i]][coord_O[i+ 1]] == 'O')
            nb_O = nb_O + 1;
        i = i + 2;
    }
    return (nb_O);
}

void my_put_map(char **map, int *coord_O, int nb)
{
    int x = (LINES / 2) - (get_lgs(map) / 2);
    int y = (COLS / 2) - (my_strlen(map[0]) / 2);
    int i = 0;
    int ii = 0;
    int nb_O = count_o(map, coord_O);
    WINDOW *win = newwin(get_lgs(map) + 2, my_str\
len(map[get_longer(map)]) + 2, x - 1, y - 1);

    refresh();
    box(win, 0, 0);
    wrefresh(win);
    start_color();
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvprintw(x - 2, COLS / 2 - 1, "O = %d", nb_O);
    attroff(COLOR_PAIR(4));
    if (too_small(map) == 0)
        while (map[i]) {
            while (map[i][ii] != '\0') {
                if (map[i][ii] == 'X') {
                    start_color();
                    init_pair(1, COLOR_RED, COLOR_BLACK);
                    attron(COLOR_PAIR(1));
                    mvprintw(x, y, "%c", map[i][ii]);
                    attroff(COLOR_PAIR(1));
                } else if (map[i][ii] == 'O') {
                    start_color();
                    init_pair(2, COLOR_CYAN, COLOR_BLACK);
                    attron(COLOR_PAIR(2));
                    mvprintw(x, y, "%c", map[i][ii]);
                    attroff(COLOR_PAIR(2));
                } else if (map[i][ii] == '#') {
                    start_color();
                    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
                    attron(COLOR_PAIR(3));
                    mvprintw(x, y, "%c", map[i][ii]);
                    attroff(COLOR_PAIR(3));
                } else {
                    start_color();
                    init_pair(5, COLOR_WHITE, COLOR_BLACK);
                    attron(COLOR_PAIR(5));
                    mvprintw(x, y, "%c", map[i][ii]);
                    attroff(COLOR_PAIR(5));
                }
                ii = ii + 1;
                y = y + 1;
            }
            y = (COLS / 2) - (my_strlen(map[0]) / 2);
            ii = 0;
            x = x + 1;
            i = i + 1;
        }
    start_color();
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvprintw(x + 1, COLS / 2 - 10, "remaining mouvements : %d", nb);
    attroff(COLOR_PAIR(4));
}
