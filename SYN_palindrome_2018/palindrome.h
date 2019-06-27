/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** tetris is NOT a battle royal
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    int base;
    int is_base;
    int imin;
    int is_min;
    int imax;
    int is_max;
}PALINDROME_t;

int my_atoi(char const *str);
void argumenter(int ac, char **av, PALINDROME_t *pal);
void declarer(PALINDROME_t *pal);
char *from_ten_to_base(char *nbr, PALINDROME_t *pal);
char *addinv(char *nbr, PALINDROME_t *pal);
char *inverser(char *nbr);
int check_palindrome(char *nbr);
void calculator(PALINDROME_t *pal, char * nbr, char *origin);
int from_base_to_ten(char *nbr, PALINDROME_t *pal);
char *my_itoa(int nb);
char *my_int_str(long nb);
void papy_calculator(PALINDROME_t *pal, char *nbr, char *goal);
void papydrome(PALINDROME_t *pal, char *nbr);
void is_num(char *num, int f);
int tester(int x, char **av, PALINDROME_t *pal);