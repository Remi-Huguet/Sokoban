/*
** EPITECH PROJECT, 2021
** coord_x
** File description:
** coord_x
*/

void is_x(char a, int *nb)
{
    if (a == 'X')
        *nb = *nb + 1;
}

int count_x(char **map)
{
    int i = 0;
    int y = 0;
    int nb = 0;

    while (map[i]) {
        while (map[i][y] != '\0') {
            is_x(map[i][y], &nb);
            y = y + 1;
        }
        y = 0;
        i = i + 1;
    }
    return (nb);
}

int get_coor(char carac, int *index_tab, int *coord_O, int *tab)
{
    if (carac == 'X') {
        coord_O[*index_tab] = tab[0];
        *index_tab = *index_tab + 1;
        coord_O[*index_tab] = tab[1];
        *index_tab = *index_tab + 1;
    }
    return (0);
}

int *get_all_coor(char **map, int *coord_O)
{
    int index_tab = 0;
    int lgs = 0;
    int cls = 0;

    while (map[lgs]) {
        while (map[lgs][cls] != '\0' && map[lgs][cls] != '\n') {
            int tab[] = {lgs, cls};

            get_coor(map[lgs][cls], &index_tab, coord_O, tab);
            cls = cls + 1;
        }
        cls = 0;
        lgs = lgs + 1;
    }
    coord_O[index_tab] = -10;
    return (coord_O);
}
