/*
** EPITECH PROJECT, 2021
** my_put
** File description:
** my_put
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (i);
}

int my_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the ware");
    my_putstr("house map, containing '#' for walls, \n");
    my_putstr("         'P' for the player, 'X' for bo");
    my_putstr("xes and 'O' for storage locations.\n");
    return (0);
}
