/*
** EPITECH PROJECT, 2019
** my is prime
** File description:
** detect if its a prime number
*/
#include <stdio.h>

int is_prime(int nb)
{
    int two = nb % 2;
    int three = nb % 3;

    if (nb == 2)
        return (1);
    if (nb == 3)
        return (1);
    if (two == 0)
        return (0);
    if (three == 0)
        return (0);
    return (1);
}

int more_ten(int nb)
{
    int mod = 2;
    int nbr = 0;
    int result;

    while (mod < 10) {
        result = nb % mod;
        if (result == 0)
            return (0);
        mod++;
    }
    return (1);
}

int my_is_prime(int nb)
{
    int less = 0;
    int more = 0;

    if (nb <= 1)
        return (0);
    if (nb < 10) {
        less = is_prime(nb);
        if (less == 0)
            return (0);
        if (less == 1)
            return (1);
    }
    more = more_ten(nb);
    if (more == 1)
        return (1);
    return (0);
}
