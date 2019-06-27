/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** main
*/

#include "palindrome.h"

int malloc_ten_to_base(char *nbr, PALINDROME_t *pal)
{
    int x = my_atoi(nbr);
    int i = 0;
    while (x >= pal->base) {
        x = x /pal->base;
        i++;
    } i = i + 2;
    return (i);
}

char *from_ten_to_base(char *nbr, PALINDROME_t *pal)
{
    int i = malloc_ten_to_base(nbr, pal);
    int x = my_atoi(nbr);
    int y = 0;
    char *based = malloc(sizeof(char) * i);
    i = i - 2;
    while (i >= 0) {
        y = x % pal->base;
        based[i] = y + 48;
        x = x / pal->base;
        i--;
    }
    return (based);
    
}

int from_base_to_ten(char *nbr, PALINDROME_t *pal)
{
    int i = 0;
    long x = 0;
    int y = 0;
    while (nbr[i + 1] != '\0') {
        y = nbr[i] - 48;
        x = (x + y) * pal->base;
        i++;
    } y = nbr[i] - 48;
    x = x + y;
    return (x);
}