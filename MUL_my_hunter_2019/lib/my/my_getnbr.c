/*
** EPITECH PROJECT, 2019
** my getnbr
** File description:
** function that found number in a string
*/

#include <stdio.h>
#include <unistd.h>

void sign(char const *str, int x)
{
    int plus = 0;
    int neg = 0;
    int less = 0;

    while (str[x] == 45 || str[x] == 43) {
        if (str[x] == 43) {
            plus++;
            x++;
        }
        if (str[x] == 45) {
            less++;
            x++;
        }
    }
    less = less % 2;
    plus = plus % 2;
    if (less == 1) {
        neg = 1;
        my_putchar('-');
    }
}

int write_nbr(char const *str, int x, int stop_nbr)
{
    while (str[x] > 47 && str[x] < 58 && stop_nbr == 0) {
        my_putchar(str[x]);
        x++;
        if (str[x] < 48 || str[x] > 57)
            stop_nbr = 1;
    }
    stop_nbr = 1;
    x++;
    return (0);
}

int funct_call(char const *str, int x, int stop_sign)
{
    int i = my_strlen(str);
    int stop_nbr = 0;

    while (i > x) {
        if (str[x] == 45 && stop_sign == 0) {
            sign(str, x);
            stop_sign = 1;
        }
        if (str[x] > 47 && str[x] < 58) {
            write_nbr(str, x, stop_nbr);
            stop_nbr = 1;
        }
        if (str[x] < 45 || str[x] > 57)
            x++;
        x++;
    }
    my_putchar('\n');
    return (0);
}

int my_getnbr(char const *str)
{
    int x = 0;
    int stop_nbr = 0;
    int stop_sign = 0;
    int i = my_strlen(str);

    if (i >= 9) {
        if (str[8] >= 48 && str[7] <= 52 && str[0] == 2) {
            return (0);
        }
        if (str[8] >= 48 && str[7] >= 52 && str[0] == '-' && str[1] <= 50) {
            return (0);
        }
    }
    funct_call(str, x, stop_sign);
    return (0);
}
