/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **my_malloc(char *buf)
{
    int i = 0;
    int j = 0;
    int nb_cols = 0;
    int nb_line = 0;

    while (buf[i] != '\0') {
        while (buf[i] != '\n') {
            j++;
            i++;
        }
        nb_cols = j;
        j = 0;
        nb_line++;
        i++;
    }
    return (mem_alloc_2d_array(nb_line, nb_cols));
}

void print_(char **map, char *d, int h)
{
    int i = 0;
    int j = 0;
    int n = 0;
    char *buf = malloc(sizeof(char) * (h + 1));

    while (map[j][n] != '\0') {
        while (map[j][n] != '\n') {
            buf[i] = map[j][n];
            i++;
            n++;
        }
        buf[i] = map[j][n];
        if (map[j][n] != '\0') {
            i++;
            j++;
            n = 0;
        }
    }
    buf[i] = map[j][n];
    write(1, buf, my_strlen(buf));
}

void square(char **map, int max, int j, int n, int *a)
{
    int i = 0;

    while (map[j][n] != '\0' && a[i] != max) {
        while (map[j][n] != '\n' && a[i] != max) {
            i++;
            n++;
        }
        if (a[i] != max) {
            j++;
            n = 0;
            i++;
        }
    }
}

void put_x(char **map, int n, int j, int max)
{
    int l = 0;
    int i = 0;

    while (i != max) {
        while (l != max) {
            map[j][n] = 'x';
            n--;
            l++;
        }
        j--;
        n += l;
        l = 0;
        i++;
    }
}

void calcul_square(int *a, int j)
{
    int i = 0;
    int nb = 0;

    for (; a[i] != 9999; i++);
    i += 2;
    while (a[i] != 9998) {
        if (a[i] == 1 && a[i - 1] != 9999) {
            nb = a[i - 1];
            if (nb > a[i - j - 1] && a[i - j - 1] != 9999)
                nb = a[i - j - 1];
            if (nb > a[i - j] && a[i - j] != 9999)
                nb = a[i - j];
            a[i] += nb;
        }
        i++;
    }
}
