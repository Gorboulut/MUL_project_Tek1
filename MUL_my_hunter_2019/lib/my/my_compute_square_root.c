/*
** EPITECH PROJECT, 2019
** my compute square root
** File description:
** return the square root of the arguments
*/
#include <stdio.h>

int my_compute_square_root(int nb)
{
    int result = nb;
    int y = 1;
    float check_int = nb;

    if (nb < 0)
        return (0);
    if (nb == 1 || nb == 0)
        return (nb);
    while (result - y > 0) {
        result = (result + y) / 2;
        y = nb / result;
    }
    if (result * result != nb)
        return (0);
    return (result);
}
