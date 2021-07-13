/*
** EPITECH PROJECT, 2021
** include
** File description:
** include
*/
#ifndef SOKOBAN_H_
#define SOKOBAN_H_

int select_map(char *msg);
int my_putstr(char const *str);
int map_in_double_char(char *map, int nb_O, int nb);
int check_error(char *map, int nb);
int get_file(char *file, int nb);
int my_strcmp(char *str, char *dest);
int my_help(void);
int my_strlen(char const *str);
int get_lgs(char **map);
int p_find(char **map, int lgs, int cls, int *i);
int is_p(char carac, int *i);
void my_put_map(char **map, int *coord_O, int nb);
char **my_str_to_word_array(char *str);
int *get_all_coord(char **map, int *coord_O);
char **reset_o(char **map, int *coord_O);
int move_player(char **map, int command, int **nb);
int up(char **map, int lgs, int tempo, int command);
int down(char **map, int lgs, int tempo, int command);
int right(char **map, int lgs, int tempo, int command);
int left(char **map, int lgs, int tempo, int command);
int move_up(char **map, int lgs, int tempo, int command);
int move_down(char **map, int lgs, int tempo, int command);
int move_right(char **map, int lgs, int tempo, int command);
int move_left(char **map, int lgs, int tempo, int command);
int get_pos(char **map, int *lgs, int *tempo);
int is_blocked(char **map, int i, int y);
int win(char **map, int *coord_O);
int lose(char **map, int *coord_O);

#endif /* !SOKOBAN_H_ */
