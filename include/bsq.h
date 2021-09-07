/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct square {
    int d;
    int i;
    int bsquare;
} square_t;

char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char *buffer, int hauteur, int largeur);
int **clone_int(char **map, int hauteur, int largeur);
void testing_col(char **map, int hauteur, int largeur);
void testing_len(char **map, int hauteur, int largeur);

#endif /* !BSQ_H_ */
