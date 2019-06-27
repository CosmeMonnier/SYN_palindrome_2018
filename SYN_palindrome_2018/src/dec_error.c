/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/
#include "palindrome.h"

void declarer(PALINDROME_t *pal)
{
    pal->base = 10;
    pal->imin = 0;
    pal->imax = 100;
    pal->is_base = 0;
    pal->is_min = 0;
    pal->is_max = 0;
}

void error(int ac, char **av)
{
    int x = 1;
    if (ac < 2 || ac > 9) {
        printf("invalid argument\n");
        exit(84);
    } while (x < ac) {
        if (av[x][0] != '-' && (av[x][0] < '0' || av[x][0] > '9')) {
            printf("invalid argument\n");
            exit(84);
        } x++;
    } x = 1;
    while (x < ac) {
        if (av[x][0] == '-' && av[x + 1] == NULL) {
            printf("invalid argument\n");
            exit(84);
        } x++;
    }
}

void argumenter(int ac, char **av, PALINDROME_t *pal)
{
    if ((ac > 3) && (av[1][1] == 'p' || av[1][1] == 'n') &&
    (av[3][1] == 'p' || av[3][1] == 'n')) {
        printf("invalid argument\n");
        exit (84);
    }
    error(ac, av);
    int x = 1;
    while (x < ac) {
        x = tester(x, av, pal);
    } if (pal->base > 10 || pal->base < 2) {
        printf("invalid argument\n");
        exit(84);
    }
}

int tester(int x, char **av, PALINDROME_t *pal)
{
    if (av[x][0] == '-' && av[x][1] == 'b') {
        x++;
        is_num(av[x], pal->is_base);
        pal->is_base = 1;
        pal->base = my_atoi(av[x]);
    } if (av[x][0] == '-' && av[x][1] == 'i' && av[x][3] == 'i') {
        x++;
        is_num(av[x], pal->is_min);
        pal->is_min = 1;
        pal->imin = my_atoi(av[x]);
    } if (av[x][0] == '-' && av[x][1] == 'i' && av[x][3] == 'a') {
        x++;
        is_num(av[x], pal->is_max);
        pal->is_max = 1;
        pal->imax = my_atoi(av[x]);
    } x++;
    return (x);
}

void is_num(char *num, int f)
{
    int i = 0;
    while (num[i] != '\0') {
        if (num[i] < '0' || num[i] > '9') {
            printf("invalid argument\n");
            exit(84);
        }
        i++;
    } if (f == 1) {
        printf("invalid argument\n");
        exit(84);
    }
}