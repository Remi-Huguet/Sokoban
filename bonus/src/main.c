/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/
#include "../include/sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

char *get_map(int i, int *nb)
{
    if (i == 38) {
        *nb = 100;
        return ("map/map1");
    } else if (i == 169) {
        *nb = 90;
        return ("map/map2");
    }
    if (i == 34) {
        *nb = 60;
        return ("map/map3");
    } else if (i == 39)
        *nb = 70;
        return ("map/map4");
    return (NULL);
}

int put_menu(char *msg)
{
    mvprintw(LINES / 2 - 6, COLS / 2 - 2, "%s", msg);
    mvprintw(LINES / 2 - 2, COLS / 2 - 2, "map1");
    mvprintw(LINES / 2 - 1, COLS / 2 - 2, "map2");
    mvprintw(LINES / 2, COLS / 2 - 2, "map3");
    mvprintw(LINES / 2 + 1, COLS / 2 - 2, "map4");
    mvprintw(LINES / 2 + 2, COLS / 2 - 14, "Select a map (1/2/3/4/Escape)");
    return (0);
}

int select_map(char *msg)
{
    int i = 0;
    int nb = 0;

    initscr();
    curs_set(false);
    keypad(stdscr, TRUE);
    clear();
    refresh();
    put_menu(msg);
    refresh();
    while (i != 38 && i != 169 && i != 34 && i != 39 && i != 27) {
        i = getch();
        clear();
        put_menu(msg);
        refresh();
    }
    if (i == 27) {
        curs_set(true);
        keypad(stdscr, FALSE);
        clear();
        refresh();
        endwin();
        exit(0);
    }
    clear();
    refresh();
    char *map = get_map(i, &nb);

    return (get_file(map, nb));
}
int main(int ac, char **av)
{
    if (av[1] && ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            my_help();
            return (0);
        }
    return (select_map(""));
}
