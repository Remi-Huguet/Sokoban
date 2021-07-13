/*
** EPITECH PROJECT, 2021
** coord_o
** File description:
** coord_o
*/

int is_p(char carac, int *i)
{
    if (carac == 'P')
        *i = 1;
    return (0);
}

int get_lgs(char **map)
{
    int i = 0;

    while (map[i])
        i = i + 1;
    return (i);
}

int get_coord(char carac, int *index_tab, int *coord_O, int *tab)
{
    if (carac == 'O') {
        coord_O[*index_tab] = tab[0];
        *index_tab = *index_tab + 1;
        coord_O[*index_tab] = tab[1];
        *index_tab = *index_tab + 1;
    }
    return (0);
}

int *get_all_coord(char **map, int *coord_O)
{
    int index_tab = 0;
    int lgs = 0;
    int cls = 0;

    while (map[lgs]) {
        while (map[lgs][cls] != '\0' && map[lgs][cls] != '\n') {
            int tab[] = {lgs, cls};

            get_coord(map[lgs][cls], &index_tab, coord_O, tab);
            cls = cls + 1;
        }
        cls = 0;
        lgs = lgs + 1;
    }
    coord_O[index_tab] = -10;
    return (coord_O);
}

char **reset_o(char **map, int *coord_O)
{
    int i = 0;

    while (coord_O[i] != -10) {
        if (map[coord_O[i]][coord_O[i + 1]] == ' ')
            map[coord_O[i]][coord_O[i + 1]] = 'O';
        i = i + 2;
    }
    return (map);
}
