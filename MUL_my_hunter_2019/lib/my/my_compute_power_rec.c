/*
** EPITECH PROJECT, 2019
** my compute power rec
** File description:
** give the argument raise to power in recursive
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    int cpy_p = p;
    int i = 0;

    if (cpy_p == 0)
        return (1);
    if (p < 0 )
        return (0);
    if (nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, cpy_p - 1));
}
