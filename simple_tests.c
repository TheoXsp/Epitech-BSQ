/*
** EPITECH PROJECT, 2020
** simpletestsbsqfuncs
** File description:
** simple_tests
*/

#include "bsq.h"

void testing_col(char **map, int hauteur, int largeur)
{
    for (int d = 0; map[d] != NULL; d++) {
        if (map[d][0] == '.') {
            map[d][0] = 'x';
            return;
        }
    }
}

void testing_len(char **map, int hauteur, int largeur)
{
    for (int d = 0; map[0][d] != '\0'; d++) {
        if (map[0][d] == '.') {
            map[0][d] = 'x';
            return;
        }
    }
}