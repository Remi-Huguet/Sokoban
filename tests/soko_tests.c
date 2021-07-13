/*
** EPITECH PROJECT, 2021
** tests
** File description:
** tests
*/
#include "../include/sokoban.h"
#include  <criterion/criterion.h>
#include <stdlib.h>
#include <stddef.h>

Test(fct, return_value)
{
    char *str = "-h";
    char *dest = "-s";
    char *jsp = "azer";
    char *to_arrayed = "azer\nazer\nazer";
    char *map[] = {"P", NULL};
    int i = 0;

    cr_assert(my_strcmp(str, "-h") == 0);
    cr_assert(my_strcmp(dest, "-h") == -1);
    cr_assert(my_strcmp(jsp, "-h") == -1);
    cr_assert(my_str_to_word_array(to_arrayed) != NULL);
    cr_assert(p_find(map, 0, 0, &i) == 0);
    cr_assert(my_help() == 0);
}

Test(coord, return_value)
{
    char *buf = "###\n# #\n###";
    char *buffer = "#####\n#OX #\n# P #\n#   #\n#####";
    int tab[] = {1, 1, -10};
    int ta[3];
    char **map = malloc(sizeof(char) * my_strlen(buf));
    int i = 0;

    map = my_str_to_word_array(buf);
    cr_assert(reset_o(map, tab) != NULL);
    map = malloc(sizeof(char) * my_strlen(buffer));
    map = my_str_to_word_array(buffer);
    cr_assert(get_all_coord(map, ta) != NULL);
    cr_assert(is_p('P', &i) == 0);
    cr_assert(get_lgs(map) == 5);
    free(map);
}

Test(win, return_value)
{
    int tab[] = {1, 1, -10};
    char *map[] = {"###", "#X#", "###", NULL};
    char *ma[] = {"###", "# #", "###", NULL};

    cr_assert(win(map, tab) == 0);
    cr_assert(win(ma, tab) == -1);
}

Test(lose, return_value)
{
    char *map[] = {"###", "#X#", "###", NULL};
    char *mapp[] = {"#####", "#   #", "# X #", "#   #", "#####", NULL};
    int *tab = NULL;

    cr_assert(lose(map, tab) == 0);
    cr_assert(lose(mapp, tab) == 1);
}

Test(move, return_value)
{
    char *buffer = "#####\n#   #\n# P #\n#   #\n#####";
    char **map = malloc(sizeof(char) * my_strlen(buffer));

    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 0) == 0);
    cr_assert(move_player(map, 258) == 0);
    cr_assert(move_player(map, 259) == 0);
    cr_assert(move_player(map, 260) == 0);
    cr_assert(move_player(map, 261) == 0);
    free(map);
}

Test(can_t_move, return_value)
{
    char *buffer = "#####\n#####\n##P##\n#####\n#####";
    char **map = malloc(sizeof(char) * my_strlen(buffer));

    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 258) == 0);
    cr_assert(move_player(map, 259) == 0);
    cr_assert(move_player(map, 260) == 0);
    cr_assert(move_player(map, 261) == 0);
    free(map);
}

Test(move_box, return_value)
{
    char *buffer = "## ##\n# X #\n XPX \n# X #\n## ##";
    char **map = malloc(sizeof(char) * my_strlen(buffer));

    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 258) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 259) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 260) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 261) == 0);
    free(map);
}

Test(can_t_move_box_by_wall, return_value)
{
    char *buffer = "#####\n# X #\n#XPX#\n# X #\n#####";
    char **map = malloc(sizeof(char) * my_strlen(buffer));

    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 258) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 259) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 260) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 261) == 0);
    free(map);
}

Test(can_t_move_box_by_box, return_value)
{
    char *buffer = "##X##\n# X #\nXXPXX\n# X #\n##Xx##";
    char **map = malloc(sizeof(char) * my_strlen(buffer));

    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 258) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 259) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 260) == 0);
    map = my_str_to_word_array(buffer);
    cr_assert(move_player(map, 261) == 0);
    free(map);
}
