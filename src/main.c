/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/
#include "../include/sokoban.h"

int main(int ac, char **av)
{
    if (ac != 2 || !av)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        my_help();
        return (0);
    }
    return (get_file(av[1]));
}
