/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/
#include "palindrome.h"

int main(int ac, char **av)
{
    PALINDROME_t *pal = malloc(sizeof(PALINDROME_t));
    declarer(pal);
    argumenter(ac, av, pal);
    if (pal->imin > pal->imax) {
        printf("invalid argument\n");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'n') {
        calculator(pal, av[2], av[2]);
        return (0);
    } else if (av[1][0] == '-' && av[1][1] == 'p') {
        papydrome(pal, av[2]);
        return (0);
    }
}

void papydrome(PALINDROME_t *pal, char *nbr)
{
    int x = 0;
    int i = my_atoi(nbr);
    char *ix;
    if (pal->base < 10) {
        if (check_palindrome(from_ten_to_base(nbr, pal)) == 0) {
            printf("invalid argument\n");
            exit (84);
        }
    } else if (check_palindrome(nbr) == 0) {
        printf("invalid argument\n");
        exit (84);
    }
    while (x <= i) {
        ix = my_int_str(x);
        papy_calculator(pal, ix, nbr);
        x++;
    }
}

void papy_calculator(PALINDROME_t *pal, char *nbr, char *goal)
{
    int i = my_atoi(nbr);
    int x = 0;
    int j = 0;
    if (pal->base < 10) {
        nbr = from_ten_to_base(nbr, pal);
        goal = from_ten_to_base(goal, pal);
    }
    while (j < pal->imin ||
    (my_atoi(nbr) < my_atoi(goal) && j <= (pal->imax))) {
        nbr = addinv(nbr, pal);
        j++;
    }
    if (my_atoi(nbr) == my_atoi(goal) && j <= (pal->imax)) {
        x = from_base_to_ten(nbr, pal);
        nbr = my_int_str(x);
        printf("%d leads to %d in %d iteration(s) in base %d\n", i,
        from_base_to_ten(goal, pal), j, pal->base);
    }
}

void calculator(PALINDROME_t *pal, char *nbr, char *origin)
{
    long x = 0;
    int j = 0;
    if (pal->base < 10) {
        nbr = from_ten_to_base(nbr, pal);
    }
    while (j < pal->imin || (check_palindrome(nbr) == 0 && j < pal->imax)) {
        nbr = addinv(nbr, pal);
        j++;
    }
    if (j > pal->imax) {
        printf("no solution\n");
        exit(0);
    }
    x = from_base_to_ten(nbr, pal);
    nbr = my_int_str(x);
    printf("%s leads to %s in %d iteration(s) in base %d\n", origin,
    nbr, j, pal->base);
}

char *addinv(char *nbr, PALINDROME_t *pal)
{
    int inv_nbr;
    int numbr;
    char *still_nbr;
    char *inv = inverser(nbr);
    inv_nbr = from_base_to_ten(inv, pal);
    numbr = from_base_to_ten(nbr, pal);
    numbr = numbr + inv_nbr;
    still_nbr = my_int_str(numbr);
    if (pal->base < 10) {
        still_nbr = from_ten_to_base(still_nbr, pal);
    }
    return (still_nbr);
}