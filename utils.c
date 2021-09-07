/*
** EPITECH PROJECT, 2020
** utils funcs
** File description:
** utils
*/

#include "my.h"
#include "bsq.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **dest = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++)
        dest[i] = malloc(sizeof(char) * nb_cols + 1);
    return (dest);
}

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer;

    if (fd == -1) {
        write(2, "OPEN FAILED\n", 12);
        return NULL;
    }
    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, buffer, sb.st_size);
    close(fd);
    return (buffer);
}

void check_empty(char *buffer)
{
    int check = 0;
    char *str = malloc(sizeof(char) * my_strlen(buffer));

    for (int i = 0; (buffer[i] != '\0')
    || buffer[i] != '.' || buffer[i] != 'o'; i++);
    for (int i = 0; buffer[i] != '\0'; i++)
        str[i] = buffer[i];
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '.') check = 1;
    if (check == 0) {
        my_putstr(str);
        free(str);
        free(buffer);
        return;
    }
    else
        return;
}

char **load_2d_arr_from_file(char *buffer, int hauteur, int largeur)
{
    int i = 0;
    int d = 0;
    int count = 0;
    char **map;

    for (i = 0; buffer[i] != 'o' && buffer[i] != '.'; i++);
    map = mem_alloc_2d_array(hauteur, largeur);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            map[d][count] = '\0';
            d++;
            count = 0;
        } else {
            map[d][count] = buffer[i];
            count++;
        }
    }
    map[d + 1] = NULL;
    return (map);
}

int **clone_int(char **map, int hauteur, int largeur)
{
    int **intmap;
    int i = 0;
    int d = 0;

    intmap = malloc(sizeof(int *) * (hauteur + 1));
    for (i = 0; i < hauteur; i++)
        intmap[i] = malloc(sizeof(int) * largeur);
    for (d = 0; map[d] != NULL; d++) {
        for (i = 0; map[d][i] != '\0'; i++)
            (map[d][i] == '.') ? (intmap[d][i] = 1) : (intmap[d][i] = 0);
    }
    return (intmap);
}