/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** upercase every letter in a word
*/
#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] < 123 && str[i] > 96) {
            str[i] = str[i] - 32;
            i++;
        }
        i++;
    }
    return (str);
}
