/*
** EPITECH PROJECT, 2019
** my str isalpha
** File description:
** return a number if its a letter or something else
*/
#include <stdio.h>

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123) {
        if (str[i + 1] == '\0')
            return (1);
        i++;
    }
    return (0);
}
