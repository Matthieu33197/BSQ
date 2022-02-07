/*
** EPITECH PROJECT, 2019
** step by step
** File description:
** step by step
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char **mem_alloc_2d_array(int nb_row, int nb_cols)
{
    int i = 0;
    char **new_str = malloc(sizeof(char *) * nb_row);

    while (i != nb_row) {
        new_str[i] = malloc(sizeof(char) * nb_cols);
        i++;
    }
    return (new_str);
}
