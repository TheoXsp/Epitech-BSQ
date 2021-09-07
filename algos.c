/*
** EPITECH PROJECT, 2020
** fs_open_file
** File description:
** ~
*/

#include "my.h"
#include "bsq.h"

int get_little(int **intmap, int i, int d)
{
    int little = intmap[d][i - 1];

    if (intmap[d - 1][i - 1] < little)
        little = intmap[d - 1][i - 1];
    if (intmap[d - 1][i] < little)
        little = intmap[d - 1][i];
    return (little);
}

void check_neighbours(int **intmap, int i, int d, square_t *square)
{
    if (intmap[d][i] != 0 && (i != 0 || d != 0)) {
        if (intmap[d][i - 1] != 0 && intmap[d - 1][i - 1]
        != 0 && intmap[d - 1][i] != 0) {
            intmap[d][i] = 1 + get_little(intmap, i, d);
            (intmap[d][i] > square->bsquare)
        ? (square->bsquare = intmap[d][i], square->d = d, square->i = i) : 0;
        }
    }
}

void set_map(char **map, square_t *square, int hauteur, int largeur)
{
    int countd = square->d;
    int counti = square->i;

    if (largeur == 1 && hauteur == 1)
        (map[0][0] == '.') ? (map[0][0] = 'x') : (map[0][0] = 'o');
    else if (largeur == 1) {
        testing_col(map, hauteur, largeur);
        return;
    }
    else if (hauteur == 1) {
        testing_len(map, hauteur, largeur);
        return;
    }
    for (int d = 0; d < square->bsquare; d++) {
        for (int i = 0; i < square->bsquare; i++) {
            map[countd][counti] = 'x';
            counti--;
        }
        countd--;
        counti = square->i;
    }
}

void bsq(char *buffer)
{
    int i = 0;
    int d = 0;
    int largeur = 0;
    int hauteur = my_getnbr(buffer);
    char **map;
    int **intmap;
    square_t square;
    square.bsquare = 0;

    for (i = 0; buffer[i] != '.' && buffer[i] != 'o'; i++);
    for (; (buffer[i] != '\n' && buffer[i] != '\0'); i++, largeur++);
    map = load_2d_arr_from_file(buffer, hauteur, largeur);
    intmap = clone_int(map, hauteur, largeur);
    for (d = 1; d < hauteur; d++) {
        for (int i = 1; i < largeur; i++) {
            check_neighbours(intmap, i, d, &square);
        }
    }
    set_map(map, &square, hauteur, largeur);
    my_show_word_array(map);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        bsq(load_file_in_mem(av[1]));
    }
    else {
        write(2, "INVALID ARGUMENTS\n", 19);
        return (84);
    }
    return 0;
}