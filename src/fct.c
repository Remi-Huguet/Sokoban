/*
** EPITECH PROJECT, 2021
** fct
** File description:
** fct
*/
#include <stdlib.h>
#include <stddef.h>
#include <ncurses.h>

int p_find(char **map, int lgs, int cls, int *i)
{
    if (map[lgs][cls] == 'P')
        *i = 1;
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

int my_strcmp(char *str, char *dest)
{
    int len_one = my_strlen(str);
    int len_two = my_strlen(dest);
    int i = 0;

    if (len_one != len_two)
        return (-1);
    while (i <= len_one) {
        if (str[i] != dest[i])
            return (-1);
        i = i + 1;
    }
    return (0);
}

char **my_str_to_word_array(char *str)
{
    int i[] = {0, 0, 0, my_strlen(str)};
    char **args = malloc(sizeof(char *) * my_strlen(str) * 2);

    if (!args)
        return (NULL);
    for (i[0] = 0; str[i[0]] == 32; i[0] = i[0] + 1);
    while (i[0] < i[3]) {
        char *dest = malloc(sizeof(char) * my_strlen(str) * 2);

        if (!dest)
            return (NULL);
        for (i[1] = 0; str[i[0]] != '\n' && i[0] < i[3]; i[0]++, i[1]++)
            dest[i[1]] = str[i[0]];
        dest[i[1]] = '\0';
        args[i[2]] = dest;
        i[2] = i[2] + 1;
        i[0] = i[0] + 1;
    }
    return (args);
}
