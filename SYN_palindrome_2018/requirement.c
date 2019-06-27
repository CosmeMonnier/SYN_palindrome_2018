/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_factrec_synthesis(int nb)
{
    int i = 1;

    if (nb >= 13)
        return (0);
    if (nb == 1 || nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    i = nb * my_factrec_synthesis(nb - 1);
    return (i);
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;
    int x = 0;

    if (nb < 0)
        return (-1);
    while (i <= nb) {
        i = x * x;
        if (i == nb) {
            return (x);
        }
        x++;
    }
    return (-1);
}