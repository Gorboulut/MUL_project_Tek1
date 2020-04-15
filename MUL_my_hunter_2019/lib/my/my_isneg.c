/*
** EPITECH PROJECT, 2019
** my isneg
** File description:
** found if number is + or -
*/
#include <unistd.h>

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    if (n < 0)
        my_putchar('N');
    return (0);
}
