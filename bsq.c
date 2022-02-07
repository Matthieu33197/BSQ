/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find big square
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "lib/my/my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void num_point(char *buf, int *a)
{
    int i = 0;
    int n = 0;

    for (; buf[i] != '\n'; i++);
    i++;
    while (buf[i] != '\0') {
        ((buf[i] == '\n')?(a[n] = 9999):(0));
        ((buf[i] == '.')?(a[n] = 1):(0));
        ((buf[i] == 'o')?(a[n] = 0):(0));
        i++;
        n++;
    }
    a[n] = 9998;
}

unsigned int stat_file(char const *filepath)
{
    struct stat sb;

    stat(filepath, &sb);
    return (sb.st_size);
}

void copie(char *buf, char **map)
{
    int i = 0;
    int j = 0;
    int n = 0;

    for (; buf[i] != '\n'; i++);
    i++;
    while (buf[i] != '\0') {
        while (buf[i] != '\n') {
            map[j][n] = buf[i];
            n++;
            i++;
        }
        map[j][n] = buf[i];
        j++;
        i++;
        n = 0;
    }
}

void make_square(char **map, int *a)
{
    int i = 0;
    int max = a[0];
    int j = 0;
    int n = 0;

    for (i = 1; a[i] != 9998 ; i++)
        ((a[i] > max && a[i] != 9999)?(max = a[i]):(0));
    i = 0;
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
    put_x(map, n, j, max);
}

int main(int ac, char **av)
{
    int i = 0;
    int h = stat_file(av[1]);
    int *a = malloc(sizeof(int) * (h + 1));
    char *buf = malloc(sizeof(char) * (h + 1));
    int fs = open(av[1], O_RDONLY);
    int fd = read(fs, buf, (h + 1));
    char **map = my_malloc(buf);

    copie(buf, map);
    num_point(buf, a);
    for (; a[i] != 9999; i++);
    i++;
    calcul_square(a, i);
    make_square(map, a);
    print_(map, av[1], h);
    return (0);
}
