/*
** EPITECH PROJECT, 2021
** move
** File description:
** move
*/
#include "../include/sokoban.h"

int up(char **map, int lgs, int tempo, int command)
{
    if (command == 259) {
        if (!map[lgs - 1])
            return (0);
        if (map[lgs - 1][tempo] == '#')
            return (0);
        move_up(map, lgs, tempo, command);
    }
    return (0);
}

int down(char **map, int lgs, int tempo, int command)
{
    if (command == 258) {
        if (!map[lgs + 1])
            return (0);
        if (map[lgs + 1][tempo] == '#')
            return (0);
        move_down(map, lgs, tempo, command);
    }
    return (0);
}

int right(char **map, int lgs, int tempo, int command)
{
    if (command == 260) {
        if (!map[lgs][tempo - 1])
            return (0);
        if (map[lgs][tempo - 1] == '#')
            return (0);
        move_right(map, lgs, tempo, command);
    }
    return (0);
}

int left(char **map, int lgs, int tempo, int command)
{
    if (command == 261) {
        if (!map[lgs][tempo + 1])
            return (0);
        if (map[lgs][tempo + 1] == '#')
            return (0);
        move_left(map, lgs, tempo, command);
    }
    return (0);
}

int move_player(char **map, int command)
{
    int lgs = 0;
    int tempo = 0;

    if (command != 258 && command != 259 && command != 260 && command != 261)
        return (0);
    get_pos(map, &lgs, &tempo);
    up(map, lgs, tempo, command);
    down(map, lgs, tempo, command);
    right(map, lgs, tempo, command);
    left(map, lgs, tempo, command);
    return (0);
}
