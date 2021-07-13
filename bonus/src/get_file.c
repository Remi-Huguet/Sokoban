/*
** EPITECH PROJECT, 2021
** get_file
** File description:
** get_file
*/
#include "../include/sokoban.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int get_file(char *file, int nb)
{
    char *buffer;
    char *temp = malloc(sizeof(char) * 2);
    int tab[] = {0, 0, open(file, O_RDONLY)};

    if (tab[2] == -1)
        return (84);
    for (tab[1] = 0; read(tab[2], temp, 1); tab[1]++) ;
    tab[1]++;
    close(tab[2]);
    tab[0] = open(file, O_RDONLY);
    if (tab[0] == -1)
        return (84);
    buffer = malloc((sizeof(char) * tab[1]));
    read(tab[0], buffer, tab[1]);
    buffer[tab[1]] = '\0';
    close(tab[0]);
    free(temp);
    if (!buffer)
        return (84);
    return (check_error(buffer, nb));
}
