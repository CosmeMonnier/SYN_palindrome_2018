/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/

#include "palindrome.h"

int my_atoi(char const *str)
{
    int nb = 0;
    int i = 0;
    int q = 1;

    if (str[0] == '-') {
        i = 1;
        q = -1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        } else {
            return (q * nb);
        }
        i++;
    }
    return (q * nb);
}

char *my_int_str(long nb)
{
    long x = 1;
    char *buff = malloc(sizeof(char) * 10);
    int i = 0;

    while ((x * 10) <= nb) {
        x = x * 10;
    }
    while (x != 0) {
        buff[i] = 48 + (nb / x);
        nb = nb % x;
        x = x / 10;
        i++;
    }
    buff[i] = '\0';
    return (buff);
}

int check_palindrome(char *nbr)
{
    int x = 0;
    int i = strlen(nbr);
    i--;
    while (x <= i) {
        if (nbr[x] == nbr[i]) {
            x++;
            i--;
        } else return (0);
    }
    return (1);
}

char *inverser(char *nbr)
{
    int i = strlen(nbr);
    i--;
    int x = 0;
    char *inv = malloc(sizeof(char) * strlen(nbr));
    while (i >= 0) {
        inv[x] = nbr[i];
        x++;
        i--;
    }
    return (inv);
}